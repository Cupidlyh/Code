#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize)
{
    int i,j,flag=0;
    for(i=0; i<numsSize; i++)//第i个元素与除了自身外的所有元素依次比较
    {
        for(j=0; j<numsSize; j++)
        {
            if(j==i)
                continue;//序号相同时跳出此次循环执行下一次循环
            if(nums[i]!=nums[j])
            {
                flag=1;
            }
            else
            {
                flag=0;//只要相同就不是所找元素，
                break;//跳出此次循环
            }
        }
        if(flag==1)
        {
            break;//比较到最后一个元素还不同时，即为所找元素，跳出整个循环
        }
    }
    if(numsSize==1)
        i=0;//当整数数组中只有一个元素时，所找元素即为此元素
    return nums[i];
}


