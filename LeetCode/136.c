#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize)
{
    int i,j,flag=0;
    for(i=0; i<numsSize; i++)//��i��Ԫ������������������Ԫ�����αȽ�
    {
        for(j=0; j<numsSize; j++)
        {
            if(j==i)
                continue;//�����ͬʱ�����˴�ѭ��ִ����һ��ѭ��
            if(nums[i]!=nums[j])
            {
                flag=1;
            }
            else
            {
                flag=0;//ֻҪ��ͬ�Ͳ�������Ԫ�أ�
                break;//�����˴�ѭ��
            }
        }
        if(flag==1)
        {
            break;//�Ƚϵ����һ��Ԫ�ػ���ͬʱ����Ϊ����Ԫ�أ���������ѭ��
        }
    }
    if(numsSize==1)
        i=0;//������������ֻ��һ��Ԫ��ʱ������Ԫ�ؼ�Ϊ��Ԫ��
    return nums[i];
}


