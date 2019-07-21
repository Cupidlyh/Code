#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(char * s){
     bool iss=true;
     char a[100000];//存筛选出来的字符串
     int i,k=0,flag=1;
     for(i=0;i<strlen(s);i++)
         if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z'))
             a[k++]=s[i];
     for(i=0;i<k;i++)
         if(a[i]>='A'&&a[i]<='Z')//因为忽略大小写字母
             a[i]=a[i]+32;//所以将大写字母转成小写字母
     for(i=0;i<k/2;i++){
         if(a[i]!=a[k-1-i]){//判断是否相等
             flag=0;
             break;
         }
     }
    if(flag==0)
        iss=false;
    return iss;
}

