#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b) {//比较器
    return *(int *)a-*(int *)b;//从小到大排序
}

int row,n;
//sum是已加到临时数组中的元素的总和，m记录temp数组元素存储的位置，num记录candidates数组中遍历到的元素的位置
void dfs(int **arr,int *candidates,int *temp,int *col,int sum,int m,int num,int candidatesSize) {
    if(sum==n) {//当和为题目所给值时
        int flag;
        if(row==0) {//第0行一定要先存储的
            col[row]=m;//记录此行元素的个数
            for(int j=0;j<m;j++)//将元素放进arr数组中
                arr[row][j]=temp[j];
            row=row+1;//开始记录下一行
        }
        else{//从第一行开始要与之前的所有行比较判断是否重复
            for(int u=row-1;u>=0;u--) {
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
    for(;num<candidatesSize;num++) {
        if(candidates[num]>n-sum)//判断当前数字是否可以加到临时数组中
            continue;
        temp[m]=candidates[num];//存进临时数组中
        sum=sum+candidates[num];//总和加上当前元素
        dfs(arr,candidates,temp,col,sum,m+1,num+1,candidatesSize);
        sum=sum-candidates[num];//从dfs中跳出时，要减去当前元素
    }
    return ;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(candidates[0]),cmp);//排序
    n=target;//n是全局变量，记录所给值
    row=0;
    int sum=0,temp[candidatesSize],i;//temp是临时存元素的数组
    int *col=(int *)malloc(1000*sizeof(int));//开辟一个记录每行有几个元素的数组
    int **arr =(int **)malloc(sizeof(int*)*1000);//开辟二维数组
    for(i=0; i<1000; i++)
        arr[i]=(int *)malloc(sizeof(int)*candidatesSize);
    dfs(arr,candidates,temp,col,sum,0,0,candidatesSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
