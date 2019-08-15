#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize){
    int mid;
    int left=0,right=numsSize-1;
    while(left<=right){//二分查找
          mid=left+(right-left)/2;
          if(mid+1<numsSize&&nums[mid]>nums[mid+1]){//判断是否出现了最小值
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
    if(mid-1>=0&&nums[mid]<nums[mid-1])//最小值在中间时，返回序号为mid的那个值
       return nums[mid];
    return nums[0];//数组也有可能就是一个升序的，所以返回首元素
}
