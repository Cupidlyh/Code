#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize){
    int i,j,temp=0,max=INT_MIN;//max��Ϊ���ε���Сֵ
    for(i=0;i<numsSize;i++){//���������һ��
        temp=0;//ÿ�ζ�Ҫ��temp������Ϊ0
        for(j=i;j>=0;j--){
            temp=temp+nums[j];//�������������еĺ�
            max=max>temp?max:temp;//ȡ����
        }
    }
    return max;
}
