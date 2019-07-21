#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a<=168)
        {
            printf("CRASH %d\n",a);
            continue;
        }
        if(b<=168)
        {
            printf("CRASH %d\n",b);
            continue;
        }
        if(c<=168)
        {
            printf("CRASH %d\n",c);
            continue;
        }
        printf("NO CRASH\n");
    }
    return 0;
}
