#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)//比较器
{
    return *(int *)a-*(int *)b;//从小到大排序
}

int row;
//i是子集中元素的个数，m记录temp数组元素存储的位置，num记录nums数组中遍历到的元素的位置
void dfs(int **arr,int *nums,int *temp,int *col,int i,int m,int num,int numsSize) {
    if(i==0) {//当个数为0时
        int flag;//用来标记是否重复
        if(row==1) {//第一行要存进去
            col[row]=m;//记录此行元素的个数
            for(int j=0;j<m;j++)//将元素放进arr数组中
                arr[row][j]=temp[j];
            row=row+1;//开始记录下一行
        }
        else{//从第二行开始要与之前的所有行比较判断是否重复
            for(int u=row-1;u>=1;u--) {
                flag=0;
                if(col[u]!=m) {
                    flag=1;
                    continue;
                }
                for(int v=0;v<col[u];v++)
                    if(arr[u][v]!=temp[v]) {
                        flag=1;
                        break;
                    }
                if(flag==1)
                    continue;
                else
                    break;
            }
        }
        if(flag==1) {//无重复时
            col[row]=m;//记录此行元素的个数
            for(int j=0;j<m;j++)//将元素放进arr数组中
                arr[row][j]=temp[j];
            row=row+1;//开始记录下一行
        }
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

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i;
    row=1;//从第一行开始存储
    qsort(nums,numsSize,sizeof(nums[0]),cmp);//先将nums数组排序
    int n=(int)pow(2,numsSize);//计算子集个数（因为有重复子集所以实际的子集个数比这个少）
    int *temp=(int *)malloc(numsSize*sizeof(int));//临时存放数组中的元素
    int *col=(int *)malloc(n*sizeof(int));//开辟一个记录每行有几个元素的数组
    int **arr =(int **)malloc(sizeof(int*)*n);//开辟二维数组
    for(i=0; i<n; i++)
        arr[i]=(int *)malloc(sizeof(int)*1000);
    col[0]=0;//子集之一是空集合
    for(i=1;i<=numsSize;i++) {//i为子集中元素的个数
        dfs(arr,nums,temp,col,i,0,0,numsSize);
    }
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
