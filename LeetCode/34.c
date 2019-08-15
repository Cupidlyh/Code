#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *arr=(int *)malloc(sizeof(int)*2);//开辟数组
    *returnSize=2;//数组大小为2
    int left=0,right=numsSize;
    while(left<right){//查找值左边界
        int mid=left+(right-left)/2;
        if(nums[mid]>=target)
            right=mid;
        else
            left=mid+1;
    }
    if(left>=0&&left<numsSize&&nums[left]==target)//限定条件
       arr[0]=left;
    else
        arr[0]=-1;
    left=0;
    right=numsSize;
    while(left<right){//查找值右边界
        int mid=left+(right-left)/2;
        if(nums[mid]<=target)
            left=mid+1;
        else
            right=mid;
    }
    if(right-1>=0&&right-1<numsSize&&nums[right-1]==target)//因为右边界找出来的是第一个大于所给值的序号，所以减1
       arr[1]=right-1;
    else
        arr[1]=-1;
    return arr;
}
