#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestDivisors(int num, int* returnSize){
    *returnSize = 2;
    int *res = (int *)malloc(sizeof(int) * 2);
    int n1 = 1,n2 = num + 1,n3 = 1,n4 = num + 2,numm,i;
    numm = n2 - n1;//因数之差
    for(i = 2; i < sqrt(num + 1) + 1; i++) {//先寻找乘积等于num + 1的两个因数
        if((num + 1) % i == 0) {//判断是否可以整除
            if(abs(numm) > abs((num + 1) / i - i)) {//判断此次找寻的两因数之差是否小于当前的因数之差
                numm = (num + 1) / i - i;
                n1 = i;
                n2 = (num + 1) / i;
            }
        }
    }
    numm = n4 - n3;
    for(i = 2; i < sqrt(num + 2) + 1; i++) {
        if((num + 2) % i == 0) {
            if(abs(numm) > abs((num + 2) / i - i)) {
                numm = (num + 2) / i - i;
                n3 = i;
                n4 = (num + 2) / i;
            }
        }
    }
    if(abs(n2 - n1) < abs(n4 - n3)) {//返回两数大小最接近的那一对因数
        res[0] = n1;
        res[1] = n2;
    }
    else {
        res[0] = n3;
        res[1] = n4;
    }
    return res;
}
