#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            {scanf("%d%d",&a,&b);
            sum=a+b;
            printf("%d\n",sum);
            }
    }
    return 0;
}

