#include <stdio.h>
#include <stdlib.h>

int reverse(int x){
    if(x==0||x==-2147483648)//这两种情况直接返回，否则影响下面运算
        return 0;
    int i,len,x1=abs(x),len1;//x1为x的绝对值
    long long int sum=0;//不能定义成int型，因为中间的运算可能会超出int的范围
    len=log10(x1)+1;//这是对数字长度的计算
    len1=len-1;
    if(x>0){
        for(i=0;i<len;i++){
            //强制类型转换也要转换成long long int，否则可能超出int的范围
            sum=sum+((x1/(long long int)pow(10,i))%10)*(long long int)pow(10,len1--);
            if(sum>2147483647){//不能超过int的最大值
                sum=0;
                break;
            }
        }
    }
    if(x<0){
        for(i=0;i<len;i++){
            sum=sum+((x1/(long long int)pow(10,i))%10)*(long long int)pow(10,len1--);
            if(sum>2147483648){//不能超过int的最小值
                sum=0;
                break;
            }
        }
        sum=sum*-1;//传进来的是负数时，因为运算的时候是没有负号，此时添上
    }
    return sum;
}
