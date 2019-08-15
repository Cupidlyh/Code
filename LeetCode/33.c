#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    if(numsSize==0)//����Ϊ��ʱ������Ѱ��
        return -1;
    int res=-1,mid;
    int left=0,right=numsSize-1;
    while(left<=right){//��һ�ζ��ֲ��ң��ҳ���Сֵ
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
    if(target>=nums[0]){//�����µ�����
        left=0;
        right=mid;
    }
    if(target<nums[0]){
        left=mid;
        right=numsSize-1;
    }
    while(left<=right){//�ڶ��ζ��ֲ���
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
