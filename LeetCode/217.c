#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
        return *(int *)a-*(int *)b;
}

bool containsDuplicate(int* nums, int numsSize){
                      if(numsSize==0||numsSize==1)
                         return false;
                      qsort(nums,numsSize,sizeof(nums[0]),cmp);//����
                      for(int i=0;i<numsSize-1;i++)//ǰһ�����һ���Ƚ�
                          if(nums[i]==nums[i+1])
                              return true;
                      return false;
}
