#include <stdio.h>
#include <stdlib.h>

char * generateTheString(int n){
    char *res = (char *)malloc(505*sizeof(char));
    int i;
    if(n % 2 == 0) {
        for(i = 0; i < n - 1; i++)
            res[i] = 'a';
        res[i++] = 'b';
    }
    else {
        for(i = 0; i < n; i++)
            res[i] = 'a';
    }
    res[i] = '\0';
    return res;
}
