#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
        int i,j=0,len=numsSize;
        for(i=0;i<len-1;){//������һ��Ԫ��ʱ������Ԫ��ǰ��
                         //len��¼��������ÿ�䶯һ�κ�Ĵ�С
            if(nums[i]==nums[i+1]){
                len--;//���ʱɾ��һ��Ԫ�أ����鳤�ȼ�һ
                for(j=i+1;j<len;j++)
                    nums[j]=nums[j+1];//ɾ������i+1��Ԫ��
            //ɾ����Ԫ��ǰ�ƣ�����Ҫԭ����ͬ��i�ͺ���Ԫ�رȽϣ�����i���Լ�
            }
            else
                i++;//�����ʱi�Լ�
        }
        if(numsSize==0)//���鳤��Ϊ0ʱ������0
        len=0;
        return len;
}
