#include <stdio.h>
#include <stdlib.h>

char * addBinary(char * a, char * b){
    char *add=(char *)malloc(1000*sizeof(char));
    char *b1=(char *)malloc(1000*sizeof(char));
    char *a1=(char *)malloc(1000*sizeof(char));
    memset(add,0,1000*sizeof(char));//�����ʼ��
    memset(a1,0,1000*sizeof(char));
    memset(b1,0,1000*sizeof(char));
    int a_len=strlen(a),b_len=strlen(b),i,len=0,j=0;
    //˭�ĳ���С������˭ǰ�油λ��ʹ�����ַ����ĳ�����ͬ
    if(a_len>b_len){
        for(i=b_len-1;i>=0;i--)
            b1[i+a_len-b_len]=b[i];
        for(i=0;i<a_len-b_len;i++)
            b1[i]='0';
        a1=a;//�����ַ���ֱ�Ӹ�������ǰ���Լ����ٵ�������
        len=a_len;
    }
    if(b_len>a_len){
        for(i=a_len-1;i>=0;i--)
            a1[i+b_len-a_len]=a[i];
        for(i=0;i<b_len-a_len;i++)
            a1[i]='0';
        b1=b;
        len=b_len;
    }
    if(a_len==b_len){
        len=a_len;
        a1=a;
        b1=b;
    }
    for(i=len-1;i>=0;i--){//��������ӵļ������
        if(a1[i]-'0'+b1[i]-'0'+j>=2){//���ڵ���2��Ҫ��λ
            add[i+1]=(a1[i]-'0'+b1[i]-'0'+j)%2+'0';//����Ӳ���λ֮��Ľ��
            j=1;//��λ
        }
        else{
            add[i+1]=(a1[i]-'0'+b1[i]-'0'+j)+'0';
            j=0;
        }
    }
    if(j==1)//������j����1����˵����Ҫ��λ�����ʱ��Ԥ���ռ��������
        add[0]=1+'0';//���ȥ
    if(add[0]=='1')
        return add;
    return add+1;//���Ԥ���ռ�û���ϣ��ʹ�����add[1]����
}
