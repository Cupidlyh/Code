#include <stdio.h>
#include <stdlib.h>

int countCharacters(char ** words, int wordsSize, char * chars){
    int sum=0,charslen=strlen(chars),i,j,k,len;
    for(i=0;i<wordsSize;i++) {
        int map[105]={0},flag1=0;//map标记字母是否被用过
        len=strlen(words[i]);//len是当前行words中字符串的长度
        for(j=0;j<len;j++) {
            int flag=0;
            for(k=0;k<charslen;k++) {
                if(map[k]==0) {
                    if(chars[k]==words[i][j]) {
                        map[k]=1;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0) {
                flag1=1;
                break;
            }
        }
        if(flag1==0)
            sum=sum+len;
    }
    return sum;
}
