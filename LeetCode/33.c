#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    if(numsSize==0)//数组为空时，不用寻找
        return -1;
    int res=-1,mid;
    int left=0,right=numsSize-1;
    while(left<=right){//第一次二分查找，找出最小值
          mid=left+(right-left)/2;
          if(mid+1>=0&&mid+1<numsSize&&nums[mid]>nums[mid+1]){
             mid=mid+1;
             break;
          }
          else{
          if(nums[mid]<nums[left])
             right=mid-1;
          else
             left=mid+1;
      }
    }
    if(target>=nums[0]){//划分新的区间
        left=0;
        right=mid;
    }
    if(target<nums[0]){
        left=mid;
        right=numsSize-1;
    }
    while(left<=right){//第二次二分查找
        mid=left+(right-left)/2;
        if(nums[mid]==target){
            res=mid;
            break;
        }
        if(nums[mid]>target)
            right=mid-1;
        if(nums[mid]<target)
            left=mid+1;
    }
    return res;
}
