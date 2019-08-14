#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize){
    int i;
    if(numsSize<=1)//数组长度小于1时无峰值
        return 0;
    if(nums[numsSize-1]>nums[numsSize-2])//如果最后一个元素大于前一个元素
        return numsSize-1;//则返回最后一个元素的序号
    for(i=1;i<=numsSize-2;i++){
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){//每个元素依次判断是否为峰值
            return i;//如果是峰值则返回此时元素的序号
        }
    }
    return 0;
}

