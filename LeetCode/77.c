#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row;
//i是子集中元素的个数，m记录temp数组元素存储的位置，num记录nums数组中遍历到的元素的位置
void dfs(int **arr,int *nums,int *temp,int *col,int i,int m,int num,int numsSize) {
    if(i==0) {//当个数为0时
        col[row]=m;//记录此行元素的个数
        for(int i=0;i<m;i++)//将元素放进arr数组中
            arr[row][i]=temp[i];
        row=row+1;//开始记录下一行
        return ;
    }
    for(;num<numsSize;num++) {
        temp[m]=nums[num];//存进临时数组中
        i=i-1;//元素个数减1
        dfs(arr,nums,temp,col,i,m+1,num+1,numsSize);
        i=i+1;//从dfs中跳出就要将元素个数重新加1
    }
    return ;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int nums[1000]={0},numsSize=0,i;//num数组存储题意所说的1—n的数字
    for(i=1;i<=n;i++)
        nums[numsSize++]=i;
    row=0;
    int temp[numsSize];//临时存放数组中的元素
    int *col=(int *)malloc(10000*sizeof(int));//开辟一个记录每行有几个元素的数组
    int **arr =(int **)malloc(sizeof(int*)*10000);//开辟二维数组
    for(i=0; i<10000; i++)
        arr[i]=(int *)malloc(sizeof(int)*k);
    dfs(arr,nums,temp,col,k,0,0,numsSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
