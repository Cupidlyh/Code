#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *arr=(int *)malloc(5000*sizeof(int));//����һ����Ž���������
    int t=0,i,arr1[5000]={0};//����arr1Ϊ��ϣ��
    *returnSize=0;
    memset(arr,0,sizeof(arr));//��ʼ��
    if(nums1Size==0&&nums2Size==0)
        return arr;
    if(nums1Size<=nums2Size){//�ж϶̵���������һ��
        for(i=0;i<nums1Size;i++)//����������
            arr1[nums1[i]]++;//��¼Ԫ�س��ֵĴ���
        for(i=0;i<nums2Size;i++)//����������
            if(arr1[nums2[i]]>=1){//���Ԫ�س��ִ������ڵ���1
                arr1[nums2[i]]=0;//��¼��Ԫ��������ֵ��Ϊ0
                arr[t++]=nums2[i];//����Ԫ�ؼ��뵽������������
            }
    }
    else{
        for(i=0;i<nums2Size;i++)
            arr1[nums2[i]]++;
        for(i=0;i<nums1Size;i++)
            if(arr1[nums1[i]]>=1){
                arr1[nums1[i]]=0;
                arr[t++]=nums1[i];
            }
    }
    *returnSize=t;//����������Ԫ�صĸ���
    return arr;
}

