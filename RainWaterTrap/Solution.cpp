#include "Solution.hpp"
#include "stdio.h"
#include <string.h>

Solution::Solution()
{

}
Solution::~Solution()
{

}
int Solution::RainWaterTrapped(int *elevations,int len)
{
    
    int ret = 0;
    int worldWidth = len;
    int worldHeight = 0;
    //1) Create a world[w,h] matrix were width is the size of the array of elevations and height is the larger elevation
    printf("Input = ");
    for(int i = 0;i < worldWidth;i++)
    {
        printf("%d",elevations[i]);
        if(elevations[i] > worldHeight)
            worldHeight = elevations[i];

    }
    printf("\n");
    char **world = new char*[worldWidth];
    for(int x = 0; x < worldWidth;x++)
        {
            world[x] = new char[worldHeight]; 
            memset(world[x],NOTHING,worldHeight);   
        }
    //2) for each column , corresponding with each elevation value, register each position with 
    //water (w) or terrain (t) according with the  y value compared with the elevation on that column. 
    //On the case of first and last column, do not register water value, leaving those positions with 0 
    printf("Step 2\n");
    for(int x = 0; x < worldWidth;x++)
        {
            for(int y = 0;y< worldHeight;y++)
            {
                if(y<(elevations[x]))
                    world[x][y] = TERRAIN;
                else if(x>0 &&  (x<worldWidth-1))
                    world[x][y]= WATER;
            }   
        }
        PrintWorld(world,worldWidth,worldHeight);
    //3) For the second to the penultimate column, register 0 on positions that have no confined water. 
    //Confined water:    Is a position p(x,y)= w were:
    //                   p(x-1,y)= t or w
    //                   and 
    //                   p(x,y-1) = t or w
    // Pass this analisis from left to right and from right to left 

    //FIXME: optimise those passes

    //first pass
    printf("Step 3\n");
    for(int x = 1; x < worldWidth-1;x++)
        {
            for(int y = 0;y< worldHeight;y++)
            {
                char left = world[x-1][y];
                char right = world[x+1][y];
                char down = TERRAIN;
                if(y > 0)
                    down = world[x][y-1];
                
                if(world[x][y]==WATER)
                    {
                        //Check not confinned water
                        if(!((left==TERRAIN || left==WATER) && 
                            (down==TERRAIN || down==WATER)  &&
                            (right==TERRAIN || right==WATER)))
                            world[x][y] = NOTHING;

                    }
                
            }
                
        }

        //last pass
        for(int x = worldWidth-2; x >0;x--)
        {
            for(int y = 0;y< worldHeight;y++)
            {
                char left = world[x-1][y];
                char right = world[x+1][y];
                char down = TERRAIN;
                if(y > 0)
                    down = world[x][y-1];
                
                if(world[x][y]==WATER)
                    {
                        //Check not confinned water
                        if(!((left==TERRAIN || left==WATER) && 
                            (down==TERRAIN || down==WATER)  &&
                            (right==TERRAIN || right==WATER)))
                            world[x][y] = NOTHING;

                    }
                
            }
                
        }

        PrintWorld(world,worldWidth,worldHeight);
    
    //4)For all matrix, count how many positions marked with water. and return this value. 
    for(int x = 0; x < worldWidth;x++)
        {
            for(int y = 0;y< worldHeight;y++)
            {
                if(world[x][y]==WATER)
                    ret++;
            }   
        }
    
    return ret;
}

void Solution::PrintWorld(char **world,int width,int height)
{
    char elem[] = " =M";
    for(int y = height-1; y >= 0;y--)
        {
            for(int x = 0;x< width;x++)
            {
                printf("%c",elem[world[x][y]]);
            }
            printf("\n");   
        }
}