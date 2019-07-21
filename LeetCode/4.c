#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;//从小到大排序
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double find;
    int arr[10000],i,j;
    if(nums1Size==0&&nums2Size!=0){//当其中一个数组为空时，直接运算就可以
        if(nums2Size%2!=0)
            find=(double)nums2[nums2Size/2];
        else
            find=((double)nums2[nums2Size/2]+(double)nums2[(nums2Size/2)-1])/2;
        }
    if(nums1Size!=0&&nums2Size==0){//当其中一个数组为空时，直接运算就可以
        if(nums1Size%2!=0)
            find=(double)nums1[nums1Size/2];
        else
            find=((double)nums1[nums1Size/2]+(double)nums1[(nums1Size/2)-1])/2;
        }
    if(nums1Size!=0&&nums2Size!=0){//数组都不为空时
        for(i=0;i<nums1Size;i++)//合并数组
            arr[i]=nums1[i];
        for(j=0;j<nums2Size;j++)//合并数组
            arr[i++]=nums2[j];
        qsort(arr,nums1Size+nums2Size,sizeof(arr[0]),cmp);//排序
        if((nums1Size+nums2Size)%2!=0)//判断数组中的元素个数
            find=(double)arr[(nums2Size+nums1Size)/2];
        else
            find=((double)arr[(nums2Size+nums1Size)/2]+(double)arr[(nums2Size+nums1Size)/2-1])/2;
    }
    return find;
}
