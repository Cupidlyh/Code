#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//希尔排序
void ShellInsert(int *num,int numSize,int dk)
{
    //对数组num做一趟增量是dk的希尔插入排序
    int temp;
    int i,j;
    for(i = dk; i < numSize; i++)
    {
        if(num[i] < num[i - dk])//小于，需要将num[i]插入到有序增量子段中
        {
            temp = num[i];//将待插入记录暂存到temp中
            for(j = i - dk; j >= 0 && num[j] > temp; j -= dk)
                num[j + dk] = num[j];//记录逐个后移，直到找到插入位置
            num[j + dk] = temp;//将temp即原num[i]，插入到正确位置
        }
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int dt[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 1};
    for(int k = 0; k < 26; k++)
        ShellInsert(nums,numsSize,dt[k]);
    int *arr = nums;
    return arr;
}
