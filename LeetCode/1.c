#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,flag=0;
    *returnSize=2;//返回数组的大小是2，所以returnsize的值为2
    int *arr=(int *)malloc(2*sizeof(int));
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    arr[0]=i;
    arr[1]=j;
    return arr;
}
