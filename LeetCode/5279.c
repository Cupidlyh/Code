#include <stdio.h>
#include <stdlib.h>


int subtractProductAndSum(int n){
    long long int mul = 1,sum = 0;//mul为每一位相乘的结果，sum为每一位相加的结果
    int i,len = log10(n) + 1,temp;
    for(i = 0; i < len; i++) {//len为数字的位数
        temp = n % 10;//求出当前位的数字
        mul *= temp;
        sum += temp;
        n = n / 10;
    }
    return mul - sum;
}


