#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row,n1;
//sum是已加到临时数组中的元素的总和，i是子集中元素的个数，m记录temp数组元素存储的位置，num记录nums数组中遍历到的元素的位置
void dfs(int **arr,int *nums,int *temp,int *col,int sum,int i,int m,int num,int numsSize) {
    if(i==0&&sum==n1) {//当元素个数为0并且和为所给值
        col[row]=m;//记录此行元素的个数
        for(int i=0;i<m;i++)//将元素放进arr数组中
            arr[row][i]=temp[i];
        row=row+1;//开始记录下一行
        return ;
    }
    for(;num<numsSize;num++) {
        if(nums[num]>n1-sum)//判断当前数字是否可以加到临时数组中
           continue;
        temp[m]=nums[num];//存进临时数组
        i=i-1;//个数减一
        sum=sum+nums[num];//总和加上当前元素
        dfs(arr,nums,temp,col,sum,i,m+1,num+1,numsSize);
        i=i+1;//从dfs中跳出时，个数加一
        sum=sum-nums[num];//从dfs中跳出时，要减去当前元素
    }
    return ;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int nums[10],i,numsSize=0,sum=0;//nums数组存储1—9这9个数
    n1=n;//n1是全局变量，记录所给值n
    for(i=1;i<=9;i++)
        nums[numsSize++]=i;
    row=0;
    int temp[numsSize];//临时存放数组中的元素
    int *col=(int *)malloc(1000*sizeof(int));//开辟一个记录每行有几个元素的数组
    int **arr =(int **)malloc(sizeof(int*)*1000);//开辟二维数组
    for(i=0; i<1000; i++)
        arr[i]=(int *)malloc(sizeof(int)*k);
    dfs(arr,nums,temp,col,sum,k,0,0,numsSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
