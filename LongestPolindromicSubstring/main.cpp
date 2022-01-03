#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Coincidence matrix
struct coincidenceM
{
    bool **data;
    int size;
    char *directString;
    char *reverseString;
    bool *polidromicArray;
};

char *GetLargerPolidromicSubstring(char *s);

coincidenceM *CreateCoincidenceMatrix(char *s,bool empty);
void DestroyCoincidenceMatrix(coincidenceM *c);
void printCoincidenceMatrix(coincidenceM *c);
coincidenceM * FilterCoincidenceMatrix(coincidenceM *c);
void UpdatePolidromicArray(coincidenceM *c);
int main()
{
    char s[] = "12333123454ww3ww0987656";
    char *output = GetLargerPolidromicSubstring(s);
    return 0;
}



char *GetLargerPolidromicSubstring(char *s)
{
    if(s==NULL)
        return NULL;
    int stringSize = strlen(s);
    char *ret = new char[stringSize+1];
    ret[stringSize+1] = 0;
    //Step one : Generate coincidence matrix;
    coincidenceM *c = CreateCoincidenceMatrix(s,false);
    printf("Coincidence Matrix\n");
    printCoincidenceMatrix(c);
    //Step two : Filter coincidence matrix and update polidromic array
    coincidenceM *f = FilterCoincidenceMatrix(c);
    printf("Filtered Coincidence Matrix\n");
    printCoincidenceMatrix(f);
    
    //Step four: Analyze polidromic array to get larger polidromic substring 
    DestroyCoincidenceMatrix(c);
    DestroyCoincidenceMatrix(f);
    return ret;
}

coincidenceM *CreateCoincidenceMatrix(char *s,bool empty)
{
    coincidenceM *c = new coincidenceM();
    c->size = strlen(s);
    c->directString = new char[c->size+1];
    c->reverseString = new char[c->size+1];
    c->directString[c->size] = 0;
    c->reverseString[c->size] = 0;
    c->polidromicArray = new bool[c->size];
    memset(c->polidromicArray,0,c->size);
    strcpy(c->directString,s);
    
    for(int y = 0; y < c->size;y++)
    {
        int x = (c->size-1)-y;
        c->reverseString[y] = c->directString[x];
    }
    c->data = new bool*[c->size];
    for(int x = 0; x < c->size;x++)
        {
            c->data[x] = new bool[c->size];
            memset ( c->data[x],0,c->size);
            if(!empty)
            {
                for(int y = 0;y < c->size;y++)
                {
                    if(c->directString[x]==c->reverseString[y])
                        c->data[x][y]=true;
                }
            }
        }
    return c;

}
void DestroyCoincidenceMatrix(coincidenceM *c)
{
for(int i = 0; i < c->size;i++)
        {
            delete c->data[i];
            c->data[i] = NULL;
        }
    delete c->data;
    delete c->reverseString;
    delete c->directString;
    delete c->polidromicArray;
    delete c;
}

void printCoincidenceMatrix(coincidenceM *c)
{
    printf("directString = %s\n",c->directString);
    printf("reverseString = %s\n",c->reverseString);    
    for(int y = (c->size-1); y >= 0;y--)
        {
            printf("%c| ",c->reverseString[y]);
            for(int x=0; x < c->size;x++)
                {
                    if(c->data[x][y]==true)
                        printf(". ");
                    else
                        printf("  ");
                }
            printf("\n");
        }
        printf(" |");
    for(int i = 0 ; i < c->size;i++)
        {
            printf("%c ",c->directString[i]);
        }
    printf("\n");
    printf("Polidromic Array\n |");
    for(int i = 0 ; i < c->size;i++)
        {
            if(c->polidromicArray[i]==true)
                printf(". ");
            else    
                printf("  ");
        }
    printf("\n");
}

coincidenceM * FilterCoincidenceMatrix(coincidenceM *c)
{
    coincidenceM *ret = CreateCoincidenceMatrix(c->directString,true); 
    for(int x = 0; x < c->size;x++)
    {
        for(int y = 0; y < c->size;y++)
        {
            if(c->data[x][y]==true)
            {
                
                if(x>0 && y>0)
                {
                    if(c->data[x-1][y-1]==true)
                        {
                            ret->data[x][y] = true;
                        }
                }
                if( ret->data[x][y] == false )
                {
                    if(x<(c->size-1) && y<(c->size-1))
                    {
                        if(c->data[x+1][y+1]==true)
                            {
                                ret->data[x][y] = true;
                            }
                    }     
                }

                
            }
        }
    }
    UpdatePolidromicArray(ret);
    return ret;
}

void UpdatePolidromicArray(coincidenceM *c)
{
    for(int x = 0; x < c->size;x++)
    {
        for(int y = 0; y < c->size;y++)
        {
            if(c->data[x][y]==true)
            {
                c->polidromicArray[x]=true;
            }
        }
    }
}