#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int* nums, int numsSize){
    int j,i,temp,num=numsSize;
    if(numsSize==0)//�����СΪ0ʱ
        return ;
    for(i=numsSize-2;i>=0;i--) {//�ҵ���һ��iʹnums[i]<nums[i+1]
        if(nums[i+1]>nums[i])
            break;
    }
    if(i>=0) {//�����ʱ����û������
        for(j=numsSize-1;j>i;j--) {//�ҵ���һ��jʹnums[j]>nums[i]
            if(nums[j]>nums[i]) {//����nums[i]��nums[j]
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                break;
            }
        }
    }
    for(j=i+1;j<(i+1+numsSize)/2;j++) {//��תi+1��numsSize-1��һ�ε�Ԫ��
        temp=nums[j];
        nums[j]=nums[num-1];
        nums[num-1]=temp;
        num--;
    }
}
