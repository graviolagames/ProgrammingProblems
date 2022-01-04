#include "Solution.hpp" 
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ret;
    int vectorLen = nums.size();
    for(int i = 0;i <= (vectorLen-k);i++)
        {
            int max = INT_MIN;
            printf("{");
            for(int j = i; j < (i+k);j++ )
                {
                    printf("%d,",nums[j]);
                    if(nums[j]>max)
                        max = nums[j];
                }
            printf("} Max = %d \n",max);
                    
        }
    

    return ret;

}