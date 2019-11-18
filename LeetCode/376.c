#include <stdio.h>
#include <stdlib.h>

int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize <= 1)//少于两个元素的序列也是摆动序列
        return numsSize;
    int up = 1, down = 1;//up代表前一时刻上升，down代表前一时刻下降
    for(int i = 0;i < numsSize - 1; i++) {//遍历数组
        if(nums[i] - nums[i + 1] < 0)//如果此时差值是负数
            up = down + 1;//所以上升的加一（摆动序列要求正负交替出现）
        if(nums[i] - nums[i + 1] > 0)//如果此时差值是正数
            down = up + 1;//所以下降的加一（摆动序列要求正负交替出现）
    }
    return (up > down ? up : down);//返回最大值
}
