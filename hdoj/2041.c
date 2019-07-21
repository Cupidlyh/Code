#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 a,b,x;
    int n,i,m,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        a=1;
        b=1;
        if(m==1||m==2)
            printf("%c\n",'1');
        else
        {
            for(j=3; j<=m; j++)
            {
                x=b;
                b=a;
                a=a+x;
            }
            printf("%I64d\n",a);
        }
    }
    return 0;
}
