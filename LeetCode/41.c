#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;//从小到大排序
}

int firstMissingPositive(int* nums, int numsSize){
    int i=1,j;
    for(j=0;j<numsSize;j++){
        if(nums[j]<=0)//将小于0的元素置为0
            nums[j]=0;
    }
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    for(j=0;j<numsSize-1;j++){
        if(nums[j]==0)//元素是0就执行下次循环
            continue;
        if(nums[j]==nums[j+1])//发现相等元素就将前一个元素置为0
            nums[j]=0;
    }
    for(j=0;j<numsSize;j++){
        if(nums[j]<=0)
            continue;//元素是0就执行下次循环
        if(nums[j]==i)//i从1开始，如果等于i就使i加1
            i++;
        else{
            break;//和i不相等时就直接跳出循环，此时i即为所求值
        }
    }
    return i;
}


