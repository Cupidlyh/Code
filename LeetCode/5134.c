#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize){
    int i,j;
    int *arr1 = (int *)malloc(sizeof(int) * 10005);//结果数组
    for(i = 0; i < arrSize - 1; i++) {
        int temp = 0;
        for(j = i + 1; j < arrSize; j++) {//在第i个元素右边的元素中找一个最大值
            if(temp < arr[j])
                temp = arr[j];
        }
        arr1[i] = temp;
    }
    arr1[arrSize - 1] = -1;//最后一个元素换成-1
    *returnSize = arrSize;
    return arr1;
}
