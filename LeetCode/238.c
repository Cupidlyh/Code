#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *arr=malloc(numsSize*sizeof(int));
    int i,k=1;
    for(i=0;i<numsSize;i++){//计算当前元素左边的乘积
        arr[i]=k;
        k=k*nums[i];
    }
    k=1;
    for(i=numsSize-1;i>=0;i--){//用上一步的计算结果继续计算当前元素右边的乘积
        arr[i]=arr[i]*k;
        k=k*nums[i];
    }
    *returnSize=numsSize;
    return arr;
}
