#include <stdio.h>
#include <stdlib.h>

int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    //arr����洢����num��¼�����������ĸ���
    int arr[55][55] = {0},num = 0,i,j,k;
    for(i = 0; i < indicesSize; i++) {//����indices�����е�ֵ������Ķ�Ӧ���к��е�ֵ��1
        for(j = 0; j < m; j++)
            arr[indices[i][0]][j]++;
        for(k = 0; k < n; k++)
            arr[k][indices[i][1]]++;
    }
    for(i = 0; i < n; i++)//ͳ�ƾ����������ĸ���
        for(j = 0; j < m; j++)
            if(arr[i][j] % 2 != 0)
                num++;
    return num;
}
