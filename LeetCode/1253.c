#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes){
    int i,j,vis[100001] = {0},sum = upper,sum1 = 0,sum2 = 0;//vis为标记数组
    int **res = (int **)malloc(sizeof(int *) * 2);//开辟二维数组保存结果
    for(i = 0; i < 2; i++) {
        res[i] = (int *)malloc(sizeof(int) * colsumSize);
        for(j = 0; j < colsumSize; j++)
            res[i][j] = 0;
    }
    int *col = (int *)malloc(sizeof(int) * 2);//记录res数组每一行元素的个数
    col[0] = colsumSize;
    col[1] = colsumSize;
    *returnColumnSizes = col;
    *returnSize = 2;//res数组的行数
    for(i = 0; i < colsumSize; i++) {//先遍历colsum数组
        if(colsum[i] == 1)//如果和为1
            res[0][i] = 1;//第0行第i列置1
        if(colsum[i] == 2) {//如果和为2
            res[0][i] = 1;//第0行第i列置1
            res[1][i] = 1;//第1行第i列置1
            vis[i] = 1;//标记此列
            sum--;//第0行的总和减1
        }
    }
    for(i = 0; i < colsumSize; i++) {//第一遍遍历res数组的第0行
        if(sum == 0)//总和为0时跳出循环
            break;
        if(res[0][i] == 1 &&vis[i] == 0) {//如果第0行第i列为1且没被标记
            sum--;////第0行的总和减1
            vis[i] = 1;//标记此列
        }
    }
    for(i = 0; i < colsumSize; i++) {//第二遍遍历res数组的第0行
        if(vis[i] == 0 &&res[0][i] == 1) {//未被标记的且第0行第i列为1的
            res[0][i] = 0;//第0行和第1行的数字进行交换
            res[1][i] = 1;
        }
    }
    for(i = 0; i < colsumSize; i++) {//遍历整个res数组
        if(res[1][i] == 1)
            sum2++;//sum2记录二维数组第1行的总和
        if(res[0][i] == 1)
            sum1++;//sum1记录二维数组第0行的总和
    }
    if(sum1 != upper || sum2 != lower) {
        *returnSize = 0;
    }
    return res;
}
