#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize){
    int a=0,b=0,c=0,i,j;
    for(i=0;i<numsSize;i++){
        if(nums[i]==0)
            a++;
        if(nums[i]==1)
            b++;
        if(nums[i]==2)
            c++;
    }
    for(i=0;i<a;i++)
        nums[i]=0;
    j=i;//j记录上一次存储到了哪个位置
    for(i=i;i<b+j;i++)
        nums[i]=1;
    j=i;
    for(i=i;i<c+j;i++)
        nums[i]=2;
}

