#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int s;
    if(target<nums[0])//�������ֵС�������е�һ��Ԫ�أ�ֱ�ӷ���0
        return 0;
    if(target>nums[numsSize-1])//�������ֵ�������������һ��Ԫ�أ�ֱ�ӷ���numsSize
        return numsSize;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>=target){
            s=i;
            break;
        }
    }
    return s;
}
