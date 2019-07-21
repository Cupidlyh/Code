#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//比较器
        return *(int *)b-*(int *)a;
 }

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof( nums[0] ),cmp);//排序函数
    return nums[k-1];
}


