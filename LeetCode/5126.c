#include <stdio.h>
#include <stdlib.h>

int findSpecialInteger(int* arr, int arrSize){
    int i;
    double k = arrSize / 4,num = 0;//k是计算占比25%的元素最低数量，num计算数组中元素数量
    for(i = 0; i < arrSize - 1; i++) {//遍历数组
        if(arr[i] == arr[i + 1]) {
            num++;//记录元素出现的次数
            if(num >= k) {//超过四分之一就跳出循环
                break;
            }
        }
        else {
            num = 0;//重置方便下次记录
        }
    }
    return arr[i];
}
