#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[8000];
//超时优化2:100000进制,  原因: k=s[j]*i+t; ==> k值不能越界, int型 --> 32位二进制 --> 10位十进制
int main()
{

    int i,j,k,t,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof(s));

        s[0]=1;
        for(i=2; i<=n; i++)
        {

            for(j=0,t=0; j<8000; j++)
            {
                k=s[j]*i+t;
                t=k/100000;
                s[j]=k%100000;
            }
        }
        for(i=8000-1; !s[i]; i--);
        printf("%d",s[i]);
        while(i)
            printf("%05d",s[--i]);

        printf("\n");
    }
    return 0;
}
