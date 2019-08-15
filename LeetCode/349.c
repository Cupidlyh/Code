#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *arr=(int *)malloc(5000*sizeof(int));//开辟一个存放交集的数组
    int t=0,i,arr1[5000]={0};//数组arr1为哈希表
    *returnSize=0;
    memset(arr,0,sizeof(arr));//初始化
    if(nums1Size==0&&nums2Size==0)
        return arr;
    if(nums1Size<=nums2Size){//判断短的数组是哪一个
        for(i=0;i<nums1Size;i++)//遍历短数组
            arr1[nums1[i]]++;//记录元素出现的次数
        for(i=0;i<nums2Size;i++)//遍历长数组
            if(arr1[nums2[i]]>=1){//如果元素出现次数大于等于1
                arr1[nums2[i]]=0;//记录此元素数量的值置为0
                arr[t++]=nums2[i];//将此元素加入到交集的数组中
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
    *returnSize=t;//交集数组中元素的个数
    return arr;
}

