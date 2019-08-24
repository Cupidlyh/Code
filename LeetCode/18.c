#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)//比较器
{
    return *(int *)a-*(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(nums[0]),cmp);//排序函数
    int i,j,row=0,s,left,right,flag=0;
    int *col=(int *)malloc(1000*sizeof(int));
    int **arr =(int **)malloc(sizeof(int*)*1000);//开辟二维数组
    for(i=0; i<1000; i++)
        arr[i]=(int *)malloc(sizeof(int)*4);
    for(i=0;i<numsSize-3;i++) {//遍历数组
        for(j=i+1;j<numsSize-2;j++) {
            if(j>i+1&&nums[j]==nums[j-1]||(i>0&&nums[i]==nums[i-1]))//去重
                continue;
            left=j+1;//左指针
            right=numsSize-1;//右指针
            while(left<right) {//循环条件
                s=nums[i]+nums[j]+nums[left]+nums[right];
                if(s<target)
                left++;
                if(s>target)
                    right--;
                if(s==target) {
                    arr[row][0]=nums[i];
                    arr[row][1]=nums[j];
                    arr[row][2]=nums[left];
                    arr[row][3]=nums[right];
                    col[row]=4;
                    row++;
                    while(left<right&&nums[left]==nums[left+1])//去重
                        left++;
                    while(left<right&&nums[right]==nums[right-1])//去重
                        right--;
                    left++;
                    right--;
                }

            }
        }
    }
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
