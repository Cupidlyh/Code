#include <stdio.h>
#include <stdlib.h>

int findPeakElement(int* nums, int numsSize){
    int i;
    if(numsSize<=1)//���鳤��С��1ʱ�޷�ֵ
        return 0;
    if(nums[numsSize-1]>nums[numsSize-2])//������һ��Ԫ�ش���ǰһ��Ԫ��
        return numsSize-1;//�򷵻����һ��Ԫ�ص����
    for(i=1;i<=numsSize-2;i++){
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){//ÿ��Ԫ�������ж��Ƿ�Ϊ��ֵ
            return i;//����Ƿ�ֵ�򷵻ش�ʱԪ�ص����
        }
    }
    return 0;
}

