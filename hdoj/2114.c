#include <stdio.h>
#include <stdlib.h>
int main()
{
    __int64 s,n;
    while(scanf("%I64d",&n)!=EOF)
    {
        s=(((n*(n+1)/2)%10000)*((n*(n+1)/2)%10000))%10000;
            printf("%04I64d\n",s);
    }
    return 0;
}
