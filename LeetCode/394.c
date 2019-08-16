#include <stdio.h>
#include <stdlib.h>

char * decodeString(char * s){
    int len=strlen(s),i,l=0,j,k,temp,l1,z,flag;//l1和flag都是用来记录临时值的
    char *stack=(char *)malloc(5000*sizeof(char));//最后返回的数组
    char arr[5000]={'0'};//辅助数组
    memset(stack,0,sizeof(stack));//数组初始化
    for(i=0;i<len;i++){
        if(s[i]!=']'){
            stack[l++]=s[i];
        }
        else{
            k=0;
            temp=0;//temp是保存数字是多少
            l1=l;//临时保存此时l的位置，即此时'[]'中字母结束的位置
            for(j=l-1;j>=0;j--)
                if(stack[j]=='[')//找到'['的位置
                    break;
            l=j-1;//'['的前一个即为数字的开始
            for(j=l;j>=0;j--){
                if(stack[j]>='0'&&stack[j]<='9')
                    temp=temp+(stack[j]-'0')*pow(10,k++);//计算出数字是多少
                else
                    break;
            }
            flag=j+1;//记录数字的起始位置，方便之后将数字覆盖存储
            k=0;
            for(j=l+2;j<l1;j++)//l+2即为'[]'中字母的起始位置，l1即为结束位置
                arr[k++]=stack[j];//将'[]'里的字母存入辅助数组中
            l=flag;
            for(j=0;j<temp;j++)
                for(z=0;z<k;z++)
                    stack[l++]=arr[z];//从数字的起始位置进行存储
        }
    }
    stack[l]='\0';//最后数组的结束标志
    return stack;//返回数组
}
