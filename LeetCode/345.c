#include <stdio.h>
#include <stdlib.h>


char * reverseVowels(char * s){
        char *str=s,m;
        int l=strlen(s),i,j=l-1;//i是头指针，j是尾指针
        for(i=0;i<l&&j>i;i++){//循环结束的条件
            while(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='A'&&str[i]!='E'&&str[i]!='I'&&str[i]!='O'&&str[i]!='U'&&i<j)//跳过非元音字母
                i++;
            while(str[j]!='a'&&str[j]!='e'&&str[j]!='i'&&str[j]!='o'&&str[j]!='u'&&str[j]!='A'&&str[j]!='E'&&str[j]!='I'&&str[j]!='O'&&str[j]!='U'&&j>i)//头指针不能大于尾指针
                j--;
            if(j>i){//元音字母的交换
            m=str[i];
            str[i]=str[j];
            str[j]=m;
            }
            j--;
        }
    return str;
}


