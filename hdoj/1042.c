#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40000
int a[max];
int main()
{
    int i,j,k,z,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[max-1]=1;
        for(i=2; i<=n; i++)
        {
            z=0;
            for(j=max-1; j>=0; j--)
            {
                k=a[j]*i+z;
                z=k/10;
                a[j]=k%10;
            }
        }
        for(k=0; k<max; k++)
            if(a[k]!=0)
                break;
        for(i=k; i<max; i++)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
