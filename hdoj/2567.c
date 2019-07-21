#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[52],str1[52];
    int n,i;
    memset(str,0,sizeof(str));
    memset(str1,0,sizeof(str1));
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s",str);
        scanf("%s",str1);
        for(i=0; i<strlen(str)/2; i++)
            printf("%c",str[i]);
        printf("%s",str1);
        for(i=strlen(str)/2; i<strlen(str); i++)
            printf("%c",str[i]);
        printf("\n");
        memset(str,0,sizeof(str));
        memset(str1,0,sizeof(str1));
    }
    return 0;
}
