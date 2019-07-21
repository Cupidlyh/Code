#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize){
                int i,j=0,k;
                for(i=0;i<numsSize;i++)
                    if(nums[i]!=0)
                        nums[j++]=nums[i];
                for(k=j;k<numsSize;k++)
                    nums[k]=0;
}
