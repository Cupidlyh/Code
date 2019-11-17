#include <stdio.h>
#include <stdlib.h>

int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    //arr数组存储矩阵，num记录矩阵中奇数的个数
    int arr[55][55] = {0},num = 0,i,j,k;
    for(i = 0; i < indicesSize; i++) {//根据indices数组中的值将矩阵的对应的行和列的值加1
        for(j = 0; j < m; j++)
            arr[indices[i][0]][j]++;
        for(k = 0; k < n; k++)
            arr[k][indices[i][1]]++;
    }
    for(i = 0; i < n; i++)//统计矩阵中奇数的个数
        for(j = 0; j < m; j++)
            if(arr[i][j] % 2 != 0)
                num++;
    return num;
}
