#include <stdio.h>
#include <stdlib.h>

int addDigits(int num){
    int n;
    if(num%9==0&&num!=0)//9�ı�����9����Ϊ0�����Ե����ж�
        n=9;//9�ı����Ľ��Ӧ��Ϊ����9
    else
        n=num%9;//����9�ı��������ֶ�9����Ϳ�����
    return n;
}
