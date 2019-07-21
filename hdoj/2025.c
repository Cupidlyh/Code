#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[101];
    int b[101],i;
    char max;
    while(scanf("%s",a)!=EOF)
    {
        max=a[0];
        memset(b,0,sizeof(b));
        for(i=0; i<strlen(a); i++)
            if(a[i]>max)
                max=a[i];
        for(i=0; i<strlen(a); i++)
            if(a[i]==max)
                b[i]=1;
        for(i=0; i<strlen(a); i++)
        {
            printf("%c",a[i]);
            if(b[i]==1)
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
