#include <stdio.h>
#include <stdlib.h>

bool search(int* nums, int numsSize, int target){
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]==target){
            return true;
        }
    }
    return false;
}
