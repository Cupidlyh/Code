#include <stdio.h>
#include <stdlib.h>

int longestConsecutive(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    int i,len=0,max=0,j,x;
    for(i=0;i<numsSize;i++){//������������
        for(j=i+1;j<numsSize;j++){
            if(nums[i]>nums[j]){
                x=nums[i];
                nums[i]=nums[j];
                nums[j]=x;
            }
        }
    }
    long long int temp=nums[0];//temp������¼ÿ��Ѱ�ҵ����е���Ԫ��
    for(i=0;i<numsSize;i++){
        if(i>0&&i<numsSize&&nums[i]==nums[i-1])//���������ͬ��Ԫ�ؾ�����
            continue;
        if(nums[i]==temp){//������
            len++;//���ȼ�1
            temp++;//��Ϊ���������У�����tempҲҪ��1
        }
        else{
            max=max>len?max:len;//ȡ����֮��ϴ��һ��
            len=0;//������Ϊ�㣬���¿�ʼ����
            temp=nums[i];//��¼����һ�����е���Ԫ��
            i=i-1;//�����i-1��Ϊ�˵���for�е���һ��i++
        }
        max=max>len?max:len;
    }
    return max;
}
