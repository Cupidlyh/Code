#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int* nums, int numsSize){
    int j,i,temp,num=numsSize;
    if(numsSize==0)//数组大小为0时
        return ;
    for(i=numsSize-2;i>=0;i--) {//找到第一个i使nums[i]<nums[i+1]
        if(nums[i+1]>nums[i])
            break;
    }
    if(i>=0) {//如果此时数组没遍历完
        for(j=numsSize-1;j>i;j--) {//找到第一个j使nums[j]>nums[i]
            if(nums[j]>nums[i]) {//交换nums[i]和nums[j]
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                break;
            }
        }
    }
    for(j=i+1;j<(i+1+numsSize)/2;j++) {//翻转i+1到numsSize-1这一段的元素
        temp=nums[j];
        nums[j]=nums[num-1];
        nums[num-1]=temp;
        num--;
    }
}
