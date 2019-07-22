#include <stdio.h>
#include <stdlib.h>

int titleToNumber(char * s){
    int i,sum=0,j=0;
    for(i=strlen(s)-1;i>=0;i--){
        sum=sum+(int)pow(26,j++)*(s[i]-'A'+1);//½øÖÆ×ª»»
    }
    return sum;
}
