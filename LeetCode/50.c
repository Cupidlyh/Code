#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n){
    long long int n1=n;//����ɳ����ͣ���ֹ�м�Խ��
    if(n<0)
        n1=-n1;//���Ȱ�ָ��ת��Ϊ������������
    double ans=1,x1=x;
    while(n1!=0){//whileѭ��������ǿ������㷨
        if(n1%2==1){
            ans=ans*x1;
        }
        x1=x1*x1;
        n1=n1/2;
    }
    if(n<0)
        ans=1/ans;//ָ��Ϊ����ʱ��Ҫ�ѽ����Ϊ����
    return ans;
}

