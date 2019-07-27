#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize){
    int dp[10000]={0},i,j,max=0;
    for(i=0;i<numsSize;i++){//求最大上升子序列的核心代码
        dp[i]=1;
        for(j=0;j<i;j++)
            if(nums[j]<nums[i])
                dp[i]=(dp[i]>dp[j]+1)?dp[i]:(dp[j]+1);//递推关系式
        max=(max>dp[i])?max:dp[i];
    }
    return max;
}
