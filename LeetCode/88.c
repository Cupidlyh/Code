#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//�Ƚ���
    return *(int *)a-*(int *)b;//��С��������
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i,j=0;
    for(i=m;i<m+n;i++)
        nums1[i]=nums2[j++];
    qsort(nums1,n+m,sizeof(nums1[0]),cmp);//������
}
