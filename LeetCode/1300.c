#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b) {
    const int p1 = *(const int*)a;
    const int p2 = *(const int*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}//从小到大排序

int findBestValue(int* arr, int arrSize, int target){
    qsort(arr,arrSize,sizeof(arr[0]),cmp);//排序
    int i,sum = 0,res = 100000,j,temp;
    for(i = 0; i < arrSize; i++) {//先将数组元素之和求一遍
        sum += arr[i];
    }
    if(sum <= target) {//如果和小于target，那数组中的元素就一个都不用换
        return arr[arrSize - 1];
    }
    for(i = target / arrSize; i <= (target / arrSize) + 3175; i++) {//i的左边界是平均值，右边界是我试出来的
        temp = 0;
        for(j = 0; j < arrSize; j++) {//数组中小于i的元素先求出和
            if(arr[j] <= i)
                temp += arr[j];
            else
                break;
        }
        temp = temp + i * (arrSize - j);//其他大于i的元素全部换成i加进去求和
        if(abs(temp - target) < abs(sum - target)) {//判断是不是比当前已经求出来的还要小
            sum = temp;
            res = i;
        }
    }
    return res;
}
