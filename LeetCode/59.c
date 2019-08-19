#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **arr=(int **)malloc(sizeof(int *)*n);//开辟n行
    int *col=(int *)malloc(sizeof(int)*n);
    int i,j,k=1;
    for(i=0; i<n; i++){
        arr[i]=(int*)malloc(sizeof(int)*n);//每一行开辟n列
        col[i]=n;
        for(j=0;j<n;j++){
            arr[i][j]=0;//数组的初始化
        }
    }
    int up=-1,down=n,left=-1,right=n;//上下左右边界
    i=0;
    j=0;
    while(k<=n*n){
        while(j<right&&k<=n*n)//向右
            arr[i][j++]=k++;
        j--;//上一步的j的自加会越界，所以减一
        i++;//防止在拐角处多存储一次元素
        up++;//遍历完毕上面的一行，更改上边界
        while(i<down&&k<=n*n)//向下
            arr[i++][j]=k++;
        i--;//上一步的i的自加会越界，所以减一
        j--;//防止在拐角处多存储一次元素
        right--;//遍历完毕右面的一列，更改右边界
        while(j>left&&k<=n*n)//向左
            arr[i][j--]=k++;
        j++;//上一步的j的自减会越界，所以加一
        i--;//防止在拐角处多存储一次元素
        down--;//遍历完毕下面的一行，更改下边界
        while(i>up&&k<=n*n)//向上
            arr[i--][j]=k++;
        i++;//上一步的i的自减会越界，所以加一
        j++;//防止在拐角处多存储一次元素
        left++;//遍历完毕左面的一列，更改左边界
    }
    *returnSize=n;
    *returnColumnSizes=col;
    return arr;
}

