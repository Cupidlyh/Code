#include <stdio.h>
#include <stdlib.h>

int jump(int* nums, int numsSize){
    int pos = numsSize - 1,step = 0; //pos为要找的位置
    while (pos > 0) { //是否到了第 0 个位置
        for (int i = 0; i < pos; i++) {
            if (nums[i] + i >= pos) {
                pos = i; //更新要找的位置
                step++;
                break;
            }
        }
    }
    return step;
}
