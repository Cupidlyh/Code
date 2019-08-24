#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)//比较器
{
    return *(int *)a-*(int *)b; //从小到大排序
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  int i,left,right,row=0,s;
  int *col=(int *)malloc(17000*sizeof(int));
  qsort(nums,numsSize,sizeof(nums[0]),cmp);//排序函数
  int **arr =(int **)malloc(sizeof(int*)*17000);//arr为二维数组
    for(i=0; i<17000; i++)
        arr[i]=(int *)malloc(sizeof(int)*3);
    for(i=0;i<numsSize-2;i++) {//遍历数组
        if(i>0&&nums[i]==nums[i-1])//去重
            continue;
        left=i+1;//左指针
        right=numsSize-1;//右指针
        while(left<right) {//循环的条件
            s=nums[i]+nums[left]+nums[right];
            if(s<0)
                left++;
            if(s>0)
                right--;
            if(s==0) {//找到答案
                arr[row][0]=nums[i];
                arr[row][1]=nums[left];
                arr[row][2]=nums[right];
                col[row]=3;
                row++;
                while(left<right&&nums[left]==nums[left+1])//去重
                    left++;
                while(left<right&&nums[right]==nums[right-1])//去重
                    right--;
                left++;//
                right--;
            }
        }
    }
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
