#include <stdio.h>
#include <stdlib.h>

bool isNumber(char * s){
    //point������¼С�����Ƿ����,sign_e������¼e�Ƿ����
    //num������¼e֮ǰ�������ֵĸ�����num1������¼e֮��������ֵĸ���
    int len=strlen(s),i=0,point=0,sign_e=0,num=0,num1=0,j=len-1;
    if(len==0)//�ַ�������Ϊ��ʱΪ����
        return false;
    while(i<len&&s[i]==' ')//ȥ���ַ���ǰ��Ŀո�
        i++;
    if(i==len)//����ַ���ȫ���ɿո����Ҳ�Ǵ����
        return false;
    while(j>=0&&s[j]==' ')//ȥ���ַ�������Ŀո�
        j--;
    if(i>j)
        return false;
    if(s[i]=='-'||s[i]=='+'){//���ȥ���ո���з���
        i=i+1;//iҪ��1
    }
    for(;i<=j;i++){
        if(s[i]==' ')//�ַ����г��ֿո��Ǵ����
            return false;
        if((s[i]>='a'&&s[i]<='z'&&s[i]!='e')||(s[i]>='A'&&s[i]<='Z'))//�����˳�e�������ĸ�Ǵ����
            return false;
        if(s[i]=='-'||s[i]=='+')//�ַ����������Գ����������ַ���
            return false;//һ����ȥ�ո���ַ�����ͷ������һ���ǽ����ų�����e�ĺ��棬��������������ٳ��־��Ǵ����
        if((s[i]=='.'&&point==1)||(s[i]=='.'&&sign_e==1)||(s[i]=='.'&&num==0&&(s[i+1]<'0'||s[i+1]>'9')))
            return false;//С����ĳ��������������ϼ��֣����Ǵ����
        if((s[i]>='0'&&s[i]<='9')&&sign_e==0)
            num++;
        if((s[i]>='0'&&s[i]<='9')&&sign_e==1)
            num1++;
        if(s[i]=='e'){
            if(num==0)//e֮ǰ���û�����Ǵ����
                return false;
            if(sign_e==1)//e��γ����Ǵ����
                return false;
            sign_e=1;
            if(s[i+1]=='-'||s[i+1]=='+'){
                i=i+1;
            }
        }
        if(s[i]=='.'&&point==0)
            point=1;
    }
    if(sign_e==1&&num1==0)//e֮��û�����Ǵ����
        return false;
    return true;
}
