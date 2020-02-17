#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * k);//�������
    *returnSize = k;
    int i,j,k1,num[105] = {0},set[105] = {0};//num�����¼ÿһ�еľ���������set�����Ǿ��������Ƿ���ֹ���set[1]��ʾ��ĳһ��ֻ��һ�����ˣ�
    for(i = 0; i < matSize; i++) {//��������
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
    while(j < k) {//���ֻҪǰk��������
        while(k1 < matSize && set[k1] == 0)//�ҳ��������еľ���������set[k1]Ϊ1����ĳһ�г��ֹ�k1�����ˣ�
            k1++;
        for(i = 0; i < matSize; i++) {//��������һ��ʱ����С�ĸ���
            if(num[i] == k1)
                res[j++] = i;//����������
            if(j == k)
                break;
        }
        k1++;
    }
    return res;
}
