#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize){
     char c;
     int i;
     for(i=0;i<sSize/2;i++){
         c=s[i];
         s[i]=s[sSize-i-1];
         s[sSize-i-1]=c;
     }
}

