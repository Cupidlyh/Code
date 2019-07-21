#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
        return *(int *)a-*(int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
                      if(numsSize==0||numsSize==1)
                         return false;
                      qsort(nums,numsSize,sizeof(nums[0]),cmp);//排序
                      for(int i=0;i<numsSize-1;i++)//前一个与后一个比较
                          if(nums[i]==nums[i+1])
                              return true;
                      return false;
}
