#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000];
    int i,n,t,j,m;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    { t=0;
        gets(a);
        m=strlen(a);
        for(j=0;j<m;j++)
        {
            if(a[j]<0||a[j]>255)
                t++;
        }
        t=t/2;
        printf("%d\n",t);
    }
    return 0;
}
