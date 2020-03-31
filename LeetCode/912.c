#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//ϣ������
void ShellInsert(int *num,int numSize,int dk)
{
    //������num��һ��������dk��ϣ����������
    int temp;
    int i,j;
    for(i = dk; i < numSize; i++)
    {
        if(num[i] < num[i - dk])//С�ڣ���Ҫ��num[i]���뵽���������Ӷ���
        {
            temp = num[i];//���������¼�ݴ浽temp��
            for(j = i - dk; j >= 0 && num[j] > temp; j -= dk)
                num[j + dk] = num[j];//��¼������ƣ�ֱ���ҵ�����λ��
            num[j + dk] = temp;//��temp��ԭnum[i]�����뵽��ȷλ��
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
