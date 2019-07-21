#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char * s)
{
    int a[1000]={},i,b=0;
    for(i=0; i<strlen(s); i++)//将字符数组的字母转换成所对应的数字一一对应存储起来
    {
        if(s[i]=='I')
            a[i]=1;
        if(s[i]=='V')
            a[i]=5;
        if(s[i]=='X')
            a[i]=10;
        if(s[i]=='L')
            a[i]=50;
        if(s[i]=='C')
            a[i]=100;
        if(s[i]=='D')
            a[i]=500;
        if(s[i]=='M')
            a[i]=1000;
    }
    for(i=0; i<strlen(s); i++)
    {
        if(a[i+1]>a[i]&&i!=strlen(s)-1)//后一个大的话就要后减前，注意不能判断到最后
        {                              //注意i不能等于strlen（s）-1，如果等于的话最后一个就没参加运算
            b=a[i+1]-a[i]+b;
            i++;//因为小于需要相减，所以两个字母参加了运算，所以需要跳过i后面的那一项
        }
        else
            b=b+a[i];

    }
    return b;
}
