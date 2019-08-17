#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
    int i,j,temp=0,max=INT_MIN;//max置为整形的最小值
    for(i=0;i<numsSize;i++){//将数组遍历一遍
        temp=0;//每次都要将temp重新置为0
        for(j=i;j>=0;j--){
            temp=temp+nums[j];//计算连续子序列的和
            max=max>temp?max:temp;//取最大和
        }
    }
    return max;
}
