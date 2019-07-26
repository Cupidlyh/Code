#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        getchar();
        while(t--)
        {
            char str[1005]= {0},str1[1005]= {0};
            int i,j=0,k,num=1;
            gets(str);
            for(i=0; i<=strlen(str); i++)
            {
                if(str[i]!=' ')
                {
                    str1[j++]=str[i];
                }
                if(str[i]==' '||str[i]=='\0')
                {
                    if(num!=1)
                        printf(" ");
                    for(k=strlen(str1)-1; k>=0; k--)
                        printf("%c",str1[k]);
                    num++;
                    j=0;
                    memset(str1,0,sizeof(str1));
                }
            }
            printf("\n");
        }
    }
    return 0;
}
