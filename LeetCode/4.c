#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;//��С��������
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double find;
    int arr[10000],i,j;
    if(nums1Size==0&&nums2Size!=0){//������һ������Ϊ��ʱ��ֱ������Ϳ���
        if(nums2Size%2!=0)
            find=(double)nums2[nums2Size/2];
        else
            find=((double)nums2[nums2Size/2]+(double)nums2[(nums2Size/2)-1])/2;
        }
    if(nums1Size!=0&&nums2Size==0){//������һ������Ϊ��ʱ��ֱ������Ϳ���
        if(nums1Size%2!=0)
            find=(double)nums1[nums1Size/2];
        else
            find=((double)nums1[nums1Size/2]+(double)nums1[(nums1Size/2)-1])/2;
        }
    if(nums1Size!=0&&nums2Size!=0){//���鶼��Ϊ��ʱ
        for(i=0;i<nums1Size;i++)//�ϲ�����
            arr[i]=nums1[i];
        for(j=0;j<nums2Size;j++)//�ϲ�����
            arr[i++]=nums2[j];
        qsort(arr,nums1Size+nums2Size,sizeof(arr[0]),cmp);//����
        if((nums1Size+nums2Size)%2!=0)//�ж������е�Ԫ�ظ���
            find=(double)arr[(nums2Size+nums1Size)/2];
        else
            find=((double)arr[(nums2Size+nums1Size)/2]+(double)arr[(nums2Size+nums1Size)/2-1])/2;
    }
    return find;
}
