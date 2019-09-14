#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor){
    if(dividend==divisor)//除数和被除数相等时
        return 1;

    if(dividend==INT_MIN) {//当被除数为负数最小值时
        if(divisor==1)//除数为1时
            return dividend;
        if(divisor==-1)//除数为-1时
            return INT_MAX;
    }
    //当除数为负数最小值时或者被除数的绝对值小于除数的绝对值
    if(divisor==INT_MIN||labs(dividend)<labs(divisor))
        return 0;
    if(divisor==1){//当除数为1时
        return dividend;
    }

    int sum=0,i=0;//sum记录除数相加的和，i记录除数相加的数量
    int div=dividend,iso=divisor;

    if(div>0&&iso>0){//被除数和除数都大于0时
        while(iso<=429496729&&5*iso<=div-sum) {//如果可以先五次五次的加
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso<=div-sum) {//再一次一次的加
            sum=sum+iso;
            i=i+1;
        }

    }

    if(div<0&&iso<0) {//被除数和除数都小于0时
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }

    }

    if(div>0&&iso<0) {//被除数大于0，除数小于0时
        div=-div;//因为负数的最小值的绝对值比正数的最大值大，所以换成负数
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }
        i=-i;//结果是负数
    }

    if(div<0&&iso>0) {//被除数小于0，除数大于0时
        iso=-iso;
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }
        i=-i;
    }

    return i;
}
