#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *arr=malloc(numsSize*sizeof(int));
    int i,k=1;
    for(i=0;i<numsSize;i++){//���㵱ǰԪ����ߵĳ˻�
        arr[i]=k;
        k=k*nums[i];
    }
    k=1;
    for(i=numsSize-1;i>=0;i--){//����һ���ļ������������㵱ǰԪ���ұߵĳ˻�
        arr[i]=arr[i]*k;
        k=k*nums[i];
    }
    *returnSize=numsSize;
    return arr;
}
