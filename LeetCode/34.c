#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *arr=(int *)malloc(sizeof(int)*2);//��������
    *returnSize=2;//�����СΪ2
    int left=0,right=numsSize;
    while(left<right){//����ֵ��߽�
        int mid=left+(right-left)/2;
        if(nums[mid]>=target)
            right=mid;
        else
            left=mid+1;
    }
    if(left>=0&&left<numsSize&&nums[left]==target)//�޶�����
       arr[0]=left;
    else
        arr[0]=-1;
    left=0;
    right=numsSize;
    while(left<right){//����ֵ�ұ߽�
        int mid=left+(right-left)/2;
        if(nums[mid]<=target)
            left=mid+1;
        else
            right=mid;
    }
    if(right-1>=0&&right-1<numsSize&&nums[right-1]==target)//��Ϊ�ұ߽��ҳ������ǵ�һ����������ֵ����ţ����Լ�1
       arr[1]=right-1;
    else
        arr[1]=-1;
    return arr;
}
