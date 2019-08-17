#include <stdio.h>
#include <stdlib.h>

int longestConsecutive(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    int i,len=0,max=0,j,x;
    for(i=0;i<numsSize;i++){//将数组先排序
        for(j=i+1;j<numsSize;j++){
            if(nums[i]>nums[j]){
                x=nums[i];
                nums[i]=nums[j];
                nums[j]=x;
            }
        }
    }
    long long int temp=nums[0];//temp用来记录每次寻找的序列的首元素
    for(i=0;i<numsSize;i++){
        if(i>0&&i<numsSize&&nums[i]==nums[i-1])//如果遇见相同的元素就跳过
            continue;
        if(nums[i]==temp){//如果相等
            len++;//长度加1
            temp++;//因为是连续序列，所以temp也要加1
        }
        else{
            max=max>len?max:len;//取二者之间较大的一个
            len=0;//长度置为零，重新开始计数
            temp=nums[i];//记录出下一段序列的首元素
            i=i-1;//这里的i-1是为了抵消for中的那一次i++
        }
        max=max>len?max:len;
    }
    return max;
}
