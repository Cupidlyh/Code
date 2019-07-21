#include <stdio.h>
#include <stdlib.h>

bool isPerfectSquare(int num){
    int i;
    for(i=1;i<=46340;i++){//因为int型最大值开根号后的结果的整数部分是46340
                          //所以i最大取值46340
        if(i*i==num)//相等时返回true，说明是完全平方数
            return true;
        if(i*i>num)//当大于时，说明此数不是完全平方数
            break;
    }
    return false;
}
