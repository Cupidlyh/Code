#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    int n=46340,i;//因为int型的最大值开平方取整等于46340
                  //所以n初值为46340
    for(i=1;i<=46340;i++){//i不能等于46341
                          //否则下面的i*i的结果会超出int型的范围
        if(i*i==x){
            n=i;
            break;
        }
        if(i*i>x){
            n=i-1;//当大于时要减去一个
            break;
        }
    }
    return n;
}
