#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *arr=(int *)malloc(5000*sizeof(int));//����һ����Ž���Ԫ�ص�����
    int t=0,i,j,arr1[10000]={0};//����arr1Ϊ�������
    *returnSize=0;
    memset(arr,0,sizeof(arr));//�����ʼ��
    if(nums1Size==0&&nums2Size==0)
        return arr;
    if(nums1Size<=nums2Size){//�ҳ��̵�����
        for(i=0;i<nums1Size;i++){//�����̵�����
            for(j=0;j<nums2Size;j++){//������������
                if(nums1[i]==nums2[j]&&arr1[j]==0){//���Ԫ����ȣ�����Ԫ��δ�����
                    arr1[j]=1;//����Ԫ�ؽ��б��
                    arr[t++]=nums1[i];//����Ԫ�ؼ��뵽������������
                    break;
                }
            }
        }
    }
    else{
        for(i=0;i<nums2Size;i++){
            for(j=0;j<nums1Size;j++){
                if(nums2[i]==nums1[j]&&arr1[j]==0){
                    arr1[j]=1;
                    arr[t++]=nums2[i];
                    break;
                }
            }
        }
    }
    *returnSize=t;//����������Ԫ�ص�����
    return arr;
}
