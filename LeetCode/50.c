#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n){
    long long int n1=n;//定义成长整型，防止中间越界
    if(n<0)
        n1=-n1;//都先把指数转换为正整数来计算
    double ans=1,x1=x;
    while(n1!=0){//while循环这里就是快速幂算法
        if(n1%2==1){
            ans=ans*x1;
        }
        x1=x1*x1;
        n1=n1/2;
    }
    if(n<0)
        ans=1/ans;//指数为负数时，要把结果变为倒数
    return ans;
}

