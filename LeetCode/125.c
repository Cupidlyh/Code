#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(char * s){
     bool iss=true;
     char a[100000];//��ɸѡ�������ַ���
     int i,k=0,flag=1;
     for(i=0;i<strlen(s);i++)
         if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z'))
             a[k++]=s[i];
     for(i=0;i<k;i++)
         if(a[i]>='A'&&a[i]<='Z')//��Ϊ���Դ�Сд��ĸ
             a[i]=a[i]+32;//���Խ���д��ĸת��Сд��ĸ
     for(i=0;i<k/2;i++){
         if(a[i]!=a[k-1-i]){//�ж��Ƿ����
             flag=0;
             break;
         }
     }
    if(flag==0)
        iss=false;
    return iss;
}

