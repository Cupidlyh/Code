#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int* nums, int numsSize){
    int i,j,flag=0,dup=0;
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(i==j)//i��j���ʱ���Լ����Լ��Ƚϡ���������
                continue;
            if(nums[i]==nums[j]){
                dup=nums[i];
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    return dup;
}
