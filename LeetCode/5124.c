#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sequentialDigits(int low, int high, int* returnSize){
    int i,j = 0,all[100] = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};//穷举所有顺次数
    int *res = (int *)malloc(sizeof(int) * 100);
    for(i = 0; i < 36; i++) {
        if(all[i] >= low && all[i] <= high)
            res[j++] = all[i];//在low到high这个范围内的数字放进结果数组中
    }
    *returnSize = j;
    return res;
}
