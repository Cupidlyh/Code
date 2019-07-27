#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int s;
    if(target<nums[0])//如果所给值小于数组中第一个元素，直接返回0
        return 0;
    if(target>nums[numsSize-1])//如果所给值大于数组中最后一个元素，直接返回numsSize
        return numsSize;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>=target){
            s=i;
            break;
        }
    }
    return s;
}
