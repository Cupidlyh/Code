#include <stdio.h>
#include <stdlib.h>


char * countAndSay(int n){
       static char a[32][5000],b;//开辟静态数组，如果不这样开辟，值无法返回
       memset(a,0,sizeof(a));//数组的初始化
       a[1][0]='1';
       a[1][1]='\0';
       a[2][0]='1';
       a[2][1]='1';
       a[2][2]='\0';
       int i,k,m,j,c;
       for(i=3;i<=n;i++){
           m=0;
           j=i-1;
           for(k=0;k<strlen(a[j]);k++){
               b=a[j][k];//b用来记录这个数字是什么
               c=1;
               while(a[j][k]==a[j][k+1]){//因为出现与前一次记录不同的数字就要重新记录，
                                        //所以循环的条件是判断是否和后一个相同
                   c++;//c用来记录这个数字出现的次数
                   k++;
               }
               a[i][m++]=c+'0';//因为返回的是字符型，所以转换一下
               a[i][m++]=b;
           }
           a[i][m++]='\0';
       }
      return a[n];
}

