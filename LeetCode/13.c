#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char * s)
{
    int a[1000]={},i,b=0;
    for(i=0; i<strlen(s); i++)//���ַ��������ĸת��������Ӧ������һһ��Ӧ�洢����
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
        if(a[i+1]>a[i]&&i!=strlen(s)-1)//��һ����Ļ���Ҫ���ǰ��ע�ⲻ���жϵ����
        {                              //ע��i���ܵ���strlen��s��-1��������ڵĻ����һ����û�μ�����
            b=a[i+1]-a[i]+b;
            i++;//��ΪС����Ҫ���������������ĸ�μ������㣬������Ҫ����i�������һ��
        }
        else
            b=b+a[i];

    }
    return b;
}
