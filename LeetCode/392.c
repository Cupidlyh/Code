#include <stdio.h>
#include <stdlib.h>

bool isSubsequence(char * s, char * t){
    int s_len=strlen(s),t_len=strlen(t),i=0,j=0;
    if(s_len==0)//���s����Ϊ0���������κ��ַ������Ӵ�
        return true;
    while(i<s_len&&j<t_len){//ѭ����ֹ����
        if(s[i]==t[j]){//�ж�s�е���ĸ�Ƿ���t�г���
            if(i==s_len-1)//������鵽��s�ַ����е����һ����ĸ��ֱ������
                return true;
            i++;//�������s�е���һ����ĸ
        }
        j++;
    }
    return false;
}


