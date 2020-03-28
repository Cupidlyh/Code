#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 105);
    *returnSize = numsSize;
    memset(res,-1,sizeof(res));//数组初始化
    int i,j;
    for(i = 0; i < numsSize; i++) {
        if(res[index[i]] == -1)//-1代表此位置没有元素，直接存入就可以
            res[index[i]] = nums[i];
        else {
            for(j = 100; j > index[i]; j--)//元素后移一位
                res[j] = res[j - 1];
            res[index[i]] = nums[i];//插进去
        }
    }
    return res;
}
