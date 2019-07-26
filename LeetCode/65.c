#include <stdio.h>
#include <stdlib.h>

bool isNumber(char * s){
    //point用来记录小数点是否出现,sign_e用来记录e是否出现
    //num用来记录e之前出现数字的个数，num1用来记录e之后出现数字的个数
    int len=strlen(s),i=0,point=0,sign_e=0,num=0,num1=0,j=len-1;
    if(len==0)//字符串长度为空时为错误
        return false;
    while(i<len&&s[i]==' ')//去掉字符串前面的空格
        i++;
    if(i==len)//如果字符串全是由空格组成也是错误的
        return false;
    while(j>=0&&s[j]==' ')//去掉字符串后面的空格
        j--;
    if(i>j)
        return false;
    if(s[i]=='-'||s[i]=='+'){//如果去掉空格后，有符号
        i=i+1;//i要加1
    }
    for(;i<=j;i++){
        if(s[i]==' ')//字符串中出现空格是错误的
            return false;
        if((s[i]>='a'&&s[i]<='z'&&s[i]!='e')||(s[i]>='A'&&s[i]<='Z'))//出现了除e以外的字母是错误的
            return false;
        if(s[i]=='-'||s[i]=='+')//字符串中最多可以出现两次这种符号
            return false;//一次在去空格后字符串的头部，另一次是紧跟着出现在e的后面，除了这两种情况再出现就是错误的
        if((s[i]=='.'&&point==1)||(s[i]=='.'&&sign_e==1)||(s[i]=='.'&&num==0&&(s[i+1]<'0'||s[i+1]>'9')))
            return false;//小数点的出现情况如果是以上几种，就是错误的
        if((s[i]>='0'&&s[i]<='9')&&sign_e==0)
            num++;
        if((s[i]>='0'&&s[i]<='9')&&sign_e==1)
            num1++;
        if(s[i]=='e'){
            if(num==0)//e之前如果没数字是错误的
                return false;
            if(sign_e==1)//e多次出现是错误的
                return false;
            sign_e=1;
            if(s[i+1]=='-'||s[i+1]=='+'){
                i=i+1;
            }
        }
        if(s[i]=='.'&&point==0)
            point=1;
    }
    if(sign_e==1&&num1==0)//e之后没数字是错误的
        return false;
    return true;
}
