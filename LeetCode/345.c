#include <stdio.h>
#include <stdlib.h>


char * reverseVowels(char * s){
        char *str=s,m;
        int l=strlen(s),i,j=l-1;//i��ͷָ�룬j��βָ��
        for(i=0;i<l&&j>i;i++){//ѭ������������
            while(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='A'&&str[i]!='E'&&str[i]!='I'&&str[i]!='O'&&str[i]!='U'&&i<j)//������Ԫ����ĸ
                i++;
            while(str[j]!='a'&&str[j]!='e'&&str[j]!='i'&&str[j]!='o'&&str[j]!='u'&&str[j]!='A'&&str[j]!='E'&&str[j]!='I'&&str[j]!='O'&&str[j]!='U'&&j>i)//ͷָ�벻�ܴ���βָ��
                j--;
            if(j>i){//Ԫ����ĸ�Ľ���
            m=str[i];
            str[i]=str[j];
            str[j]=m;
            }
            j--;
        }
    return str;
}


