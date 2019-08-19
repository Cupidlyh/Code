#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0||* matrixColSize==0){//数组为空时
        * returnSize=0;
        int *arr=(int *)malloc(2*sizeof(int));
        return arr;
    }
    int *arr=(int *)malloc((matrixSize*(* matrixColSize)+1)*sizeof(int)),i=0,j=0,k=0;
    memset(arr,0,sizeof(arr));//一维数组的初始化
    int up=-1,down=matrixSize,left=-1,right=* matrixColSize;//设置上下左右的边界
    while(k<matrixSize*(* matrixColSize)){
        while(j<right&&k<matrixSize*(* matrixColSize))//向右
            arr[k++]=matrix[i][j++];
        j--;//上一步的j的自加会越界，所以减一
        i++;//防止在拐角处的元素多存储一次
        up++;//遍历完毕上面的一行，更改上边界
        while(i<down&&k<matrixSize*(* matrixColSize))//向下
            arr[k++]=matrix[i++][j];
        i--;//上一步的i的自加会越界，所以减一
        j--;//防止在拐角处的元素多存储一次
        right--;//遍历完毕右面的一列，更改右边界
        while(j>left&&k<matrixSize*(* matrixColSize))//向左
            arr[k++]=matrix[i][j--];
        j++;//上一步的j的自减会越界，所以加一
        i--;//防止在拐角处的元素多存储一次
        down--;//遍历完毕下面的一行，更改下边界
        while(i>up&&k<matrixSize*(* matrixColSize))//向上
            arr[k++]=matrix[i--][j];
        i++;//上一步的i的自减会越界，所以加一
        j++;//防止在拐角处的元素多存储一次
        left++;//遍历完毕左面的一列，更改左边界
    }
    *returnSize=matrixSize*(* matrixColSize);
    return arr;
}
