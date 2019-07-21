#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
        int i,j=0,len=numsSize;
        for(i=0;i<len-1;){//数组少一项元素时，后面元素前移
                         //len记录的是数组每变动一次后的大小
            if(nums[i]==nums[i+1]){
                len--;//相等时删除一个元素，数组长度减一
                for(j=i+1;j<len;j++)
                    nums[j]=nums[j+1];//删除掉第i+1个元素
            //删除后元素前移，还需要原来相同的i和后面元素比较，所以i不自加
            }
            else
                i++;//不相等时i自加
        }
        if(numsSize==0)//数组长度为0时，返回0
        len=0;
        return len;
}
