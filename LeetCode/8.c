#include <stdio.h>
#include <stdlib.h>

int myAtoi(char * str){
    char arr[1000]={0};//��ѡ�������ַ���������
    int flag=0,i=0,len=strlen(str),j=0,len1;
    long long int ans=0;
    while(str[i]==' '&&i<len)//�Ƚ��ո�ȥ��
          i++;
    if(len==0||i==len||(str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))//����ֵΪ0������
        return 0;
    if(str[i]=='-'||str[i]=='+'){
        if(str[i]=='-')//����Ǹ��ű��һ��
            flag=1;
        i++;//�����Ż��߸���ʱ��iҪ��1
    }
    while(str[i]=='0')//Ҫ������ǰ�����0ȥ��
        i++;
    for(;i<len;i++){
        if(str[i]>='0'&&str[i]<='9')
            arr[j++]=str[i];//���ַ����arr������
        else
            break;
    }
    len1=j;
    if(j>=11){//��Ϊ���͵ķ�Χ���������ֵĳ��Ȳ��ܳ���10λ
        if(flag==1)//���ŵı��
                return INT_MIN;
            else
                return INT_MAX;
    }
    for(i=0;i<j;i++){
        ans=ans+(arr[i]-'0')*pow(10,len1-1-i);//������arr�е��ַ�ת��������
    }
    if(flag==1){//���ŵı��
        ans=-ans;
        if(ans<INT_MIN)//�ж��Ƿ񳬳����͵ķ�Χ
            return INT_MIN;
        else
            return ans;//û������Χ�ͷ���ans��ֵ
    }
    else{
        if(ans>INT_MAX)
            return INT_MAX;
        else
            return ans;
    }
          return 0;
}
