#include <stdio.h>
#include <stdlib.h>

bool isValid(char * s){
    int len=strlen(s),i,pop=0;//lenΪ�ַ����ĳ��ȣ�pop��ջ��ָ��
    if(len%2!=0)//����������ʱ�Ǵ����
        return false;
    if(len==0)//������0ʱ����ȷ��
        return true;
    char str[10000];//ջ
    memset(str,0,sizeof(str));//��ʼ������
    for(i=0;i<len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){//����������־ͽ�ջ
            str[pop++]=s[i];
        }
        else{
            if(pop>=1)//��ջ�д����˵�ʱ��Ž�ָ���һ
            pop=pop-1;
            //����ƥ��
            if((s[i]==']'&&str[pop]=='[')||(s[i]=='}'&&str[pop]=='{')||(s[i]==')'&&str[pop]=='(')){
            //ƥ����ȷ�ͽ�ջ��Ԫ��ȡ������Ϊ������һ��pop=pop-1�����Դ�ʱ���ﲻ�ý��ж���Ĳ���
            }
            else
                return false;//ƥ�䲻�Ͼ��Ǵ���
        }
    }
    if(pop==0)
        return true;//���ջ����Ԫ��ʱ��������ȷ��
    return false;
}
