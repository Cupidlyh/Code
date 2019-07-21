#include <stdio.h>
#include <stdlib.h>

int addDigits(int num){
    int n;
    if(num%9==0&&num!=0)//9的倍数对9求余为0，所以单独判断
        n=9;//9的倍数的结果应该为数字9
    else
        n=num%9;//不是9的倍数的数字对9求余就可以了
    return n;
}
