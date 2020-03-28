#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 105);
    *returnSize = numsSize;
    memset(res,-1,sizeof(res));//�����ʼ��
    int i,j;
    for(i = 0; i < numsSize; i++) {
        if(res[index[i]] == -1)//-1�����λ��û��Ԫ�أ�ֱ�Ӵ���Ϳ���
            res[index[i]] = nums[i];
        else {
            for(j = 100; j > index[i]; j--)//Ԫ�غ���һλ
                res[j] = res[j - 1];
            res[index[i]] = nums[i];//���ȥ
        }
    }
    return res;
}
