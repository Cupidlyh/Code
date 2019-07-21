#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *arr=(int *)malloc(2*sizeof(int));
    int i,j,flag=0;
    *returnSize=2;//返回数组的大小是2，所以returnsize的值为2
    for(i=0;i<numbersSize-1;i++){
        for(j=i+1;j<numbersSize;j++){
            if(numbers[i]+numbers[j]==target){
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    arr[0]=i+1;//因为数字的序号从1开始，而数组从序号0开始存储，所以加1
    arr[1]=j+1;
    return arr;
}
