#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheDifference(char * s, char * t){
    int a[1000],i,j;//a为标记数组
    memset(a,-1,sizeof(a));//将a赋初值为-1
    for(i=0;i<strlen(s);i++){
        for(j=0;j<strlen(t);j++){
            if(s[i]==t[j]&&a[j]==-1){//如果找到相同的字母并且a数组没被标记
                a[j]=0;//a赋值为0，也就是标记
                break;
            }
        }
    }
    for(i=0;i<strlen(t);i++){
        if(a[i]==-1)//找到没有被标记的那个元素序号
            break;
    }
    return t[i];
}

