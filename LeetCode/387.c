#include <stdio.h>
#include <stdlib.h>

int firstUniqChar(char * s){
        int first=-1,i,count[26]={};//�����ʼ��Ϊ��
        for(i=0;i<strlen(s);i++){//��һ���������
            count[s[i]-'a']=count[s[i]-'a']+1;//����ĸ���ֵĴ�����¼����
        }
        for(i=0;i<strlen(s);i++)//�ڶ����������
            if(count[s[i]-'a']==1){//�ҵ��׸�ֻ����һ�ε��Ǹ���ĸ
                first=i;
                break;
            }
        return first;
}
