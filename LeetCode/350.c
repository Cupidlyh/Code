#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *arr=(int *)malloc(5000*sizeof(int));//开辟一个存放交集元素的数组
    int t=0,i,j,arr1[10000]={0};//数组arr1为标记数组
    *returnSize=0;
    memset(arr,0,sizeof(arr));//数组初始化
    if(nums1Size==0&&nums2Size==0)
        return arr;
    if(nums1Size<=nums2Size){//找出短的数组
        for(i=0;i<nums1Size;i++){//遍历短的数组
            for(j=0;j<nums2Size;j++){//遍历长的数组
                if(nums1[i]==nums2[j]&&arr1[j]==0){//如果元素相等，并且元素未被标记
                    arr1[j]=1;//将此元素进行标记
                    arr[t++]=nums1[i];//将此元素加入到交集的数组中
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
    *returnSize=t;//交集数组中元素的数量
    return arr;
}
