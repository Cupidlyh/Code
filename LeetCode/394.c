#include <stdio.h>
#include <stdlib.h>

char * decodeString(char * s){
    int len=strlen(s),i,l=0,j,k,temp,l1,z,flag;//l1��flag����������¼��ʱֵ��
    char *stack=(char *)malloc(5000*sizeof(char));//��󷵻ص�����
    char arr[5000]={'0'};//��������
    memset(stack,0,sizeof(stack));//�����ʼ��
    for(i=0;i<len;i++){
        if(s[i]!=']'){
            stack[l++]=s[i];
        }
        else{
            k=0;
            temp=0;//temp�Ǳ��������Ƕ���
            l1=l;//��ʱ�����ʱl��λ�ã�����ʱ'[]'����ĸ������λ��
            for(j=l-1;j>=0;j--)
                if(stack[j]=='[')//�ҵ�'['��λ��
                    break;
            l=j-1;//'['��ǰһ����Ϊ���ֵĿ�ʼ
            for(j=l;j>=0;j--){
                if(stack[j]>='0'&&stack[j]<='9')
                    temp=temp+(stack[j]-'0')*pow(10,k++);//����������Ƕ���
                else
                    break;
            }
            flag=j+1;//��¼���ֵ���ʼλ�ã�����֮�����ָ��Ǵ洢
            k=0;
            for(j=l+2;j<l1;j++)//l+2��Ϊ'[]'����ĸ����ʼλ�ã�l1��Ϊ����λ��
                arr[k++]=stack[j];//��'[]'�����ĸ���븨��������
            l=flag;
            for(j=0;j<temp;j++)
                for(z=0;z<k;z++)
                    stack[l++]=arr[z];//�����ֵ���ʼλ�ý��д洢
        }
    }
    stack[l]='\0';//�������Ľ�����־
    return stack;//��������
}
