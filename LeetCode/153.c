#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize){
    int mid;
    int left=0,right=numsSize-1;
    while(left<=right){//���ֲ���
          mid=left+(right-left)/2;
          if(mid+1<numsSize&&nums[mid]>nums[mid+1]){//�ж��Ƿ��������Сֵ
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
    if(mid-1>=0&&nums[mid]<nums[mid-1])//��Сֵ���м�ʱ���������Ϊmid���Ǹ�ֵ
       return nums[mid];
    return nums[0];//����Ҳ�п��ܾ���һ������ģ����Է�����Ԫ��
}
