#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x){
    if(x<0)//负数一定不是回文数
        return false;
    if(x>=0&&x<=9)//位数为1的整数一定是回文数
        return true;
    if(x>=10){
        int len=log10(x)+1,len1=(len+1)/2,i,j=len-1;//len为传入数字的位数，len1为比较的次数
        for(i=1;i<=len1;i++){
            if((x/(int)pow(10,j))%10!=(x%(int)pow(10,i))/(int)pow(10,i-1)){//通过数学运算取数每一位的数字
                                                                           //并进行比较
                return false;
            }
            j--;
        }
    }
    return true;
}


