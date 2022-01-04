#include <stdio.h>
#include "Solution.hpp"

int main()
{
    int elevations[] = {0,1,0,2,1,0,1,10,2,1,2,1,0,12,0,2,9,0,1,3,2,1,2,1};
    int ret = 0;
    Solution solution;
    ret = solution.RainWaterTrapped(elevations,24);
    printf("Trapped water = %d\n",ret);
    return 0;
}