#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheDifference(char * s, char * t){
    int a[1000],i,j;//aΪ�������
    memset(a,-1,sizeof(a));//��a����ֵΪ-1
    for(i=0;i<strlen(s);i++){
        for(j=0;j<strlen(t);j++){
            if(s[i]==t[j]&&a[j]==-1){//����ҵ���ͬ����ĸ����a����û�����
                a[j]=0;//a��ֵΪ0��Ҳ���Ǳ��
                break;
            }
        }
    }
    for(i=0;i<strlen(t);i++){
        if(a[i]==-1)//�ҵ�û�б���ǵ��Ǹ�Ԫ�����
            break;
    }
    return t[i];
}

