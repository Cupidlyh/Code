#include <stdio.h>
#include <stdlib.h>

int myAtoi(char * str){
    char arr[1000]={0};//将选出来的字符存在这里
    int flag=0,i=0,len=strlen(str),j=0,len1;
    long long int ans=0;
    while(str[i]==' '&&i<len)//先将空格去除
          i++;
    if(len==0||i==len||(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))//返回值为0的条件
        return 0;
    if(str[i]=='-'||str[i]=='+'){
        if(str[i]=='-')//如果是负号标记一下
            flag=1;
        i++;//是正号或者负号时，i要加1
    }
    while(str[i]=='0')//要将数字前多余的0去除
        i++;
    for(;i<len;i++){
        if(str[i]>='0'&&str[i]<='9')
            arr[j++]=str[i];//将字符存进arr数组中
        else
            break;
    }
    len1=j;
    if(j>=11){//因为整型的范围限制了数字的长度不能超过10位
        if(flag==1)//负号的标记
                return INT_MIN;
            else
                return INT_MAX;
    }
    for(i=0;i<j;i++){
        ans=ans+(arr[i]-'0')*pow(10,len1-1-i);//将存在arr中的字符转换成数字
    }
    if(flag==1){//负号的标记
        ans=-ans;
        if(ans<INT_MIN)//判断是否超出整型的范围
            return INT_MIN;
        else
            return ans;//没超出范围就返回ans的值
    }
    else{
        if(ans>INT_MAX)
            return INT_MAX;
        else
            return ans;
    }
          return 0;
}
