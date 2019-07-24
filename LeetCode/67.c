#include <stdio.h>
#include <stdlib.h>

char * addBinary(char * a, char * b){
    char *add=(char *)malloc(1000*sizeof(char));
    char *b1=(char *)malloc(1000*sizeof(char));
    char *a1=(char *)malloc(1000*sizeof(char));
    memset(add,0,1000*sizeof(char));//数组初始化
    memset(a1,0,1000*sizeof(char));
    memset(b1,0,1000*sizeof(char));
    int a_len=strlen(a),b_len=strlen(b),i,len=0,j=0;
    //谁的长度小，就在谁前面补位，使两个字符串的长度相同
    if(a_len>b_len){
        for(i=b_len-1;i>=0;i--)
            b1[i+a_len-b_len]=b[i];
        for(i=0;i<a_len-b_len;i++)
            b1[i]='0';
        a1=a;//长的字符串直接赋给我在前面自己开辟的数组中
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
    for(i=len-1;i>=0;i--){//二进制相加的计算过程
        if(a1[i]-'0'+b1[i]-'0'+j>=2){//大于等于2就要进位
            add[i+1]=(a1[i]-'0'+b1[i]-'0'+j)%2+'0';//求相加并进位之后的结果
            j=1;//进位
        }
        else{
            add[i+1]=(a1[i]-'0'+b1[i]-'0'+j)+'0';
            j=0;
        }
    }
    if(j==1)//最后如果j等于1，就说明还要进位，这个时候预留空间就有用了
        add[0]=1+'0';//存进去
    if(add[0]=='1')
        return add;
    return add+1;//如果预留空间没用上，就从数组add[1]返回
}
