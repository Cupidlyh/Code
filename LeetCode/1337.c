#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * k);//结果数组
    *returnSize = k;
    int i,j,k1,num[105] = {0},set[105] = {0};//num数组记录每一行的军人数量，set数组标记军人数量是否出现过（set[1]表示有某一行只有一个军人）
    for(i = 0; i < matSize; i++) {//遍历方阵
        for(j = 0; j < *matColSize; j++) {
            if(mat[i][j] == 1) {
                num[i]++;
            }
            else
                break;
        }
        set[num[i]] = 1;
    }
    j = 0;
    k1 = 0;
    while(j < k) {//结果只要前k个最弱的
        while(k1 < matSize && set[k1] == 0)//找出弱的那行的军人数量（set[k1]为1代表某一行出现过k1个军人）
            k1++;
        for(i = 0; i < matSize; i++) {//军人数量一样时行数小的更弱
            if(num[i] == k1)
                res[j++] = i;//存进结果数组
            if(j == k)
                break;
        }
        k1++;
    }
    return res;
}
