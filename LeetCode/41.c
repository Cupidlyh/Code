#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;//��С��������
}

int firstMissingPositive(int* nums, int numsSize){
    int i=1,j;
    for(j=0;j<numsSize;j++){
        if(nums[j]<=0)//��С��0��Ԫ����Ϊ0
            nums[j]=0;
    }
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    for(j=0;j<numsSize-1;j++){
        if(nums[j]==0)//Ԫ����0��ִ���´�ѭ��
            continue;
        if(nums[j]==nums[j+1])//�������Ԫ�ؾͽ�ǰһ��Ԫ����Ϊ0
            nums[j]=0;
    }
    for(j=0;j<numsSize;j++){
        if(nums[j]<=0)
            continue;//Ԫ����0��ִ���´�ѭ��
        if(nums[j]==i)//i��1��ʼ���������i��ʹi��1
            i++;
        else{
            break;//��i�����ʱ��ֱ������ѭ������ʱi��Ϊ����ֵ
        }
    }
    return i;
}


