#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,b,m;
    char a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {m=0;
    scanf("%s",a);
    b=strlen(a);
        for(j=0;j<b;j++)
        {if(a[j]<='9'&&a[j]>='0')
        m=m+1;
        }
        printf("%d\n",m);

    }
    return 0;
}
