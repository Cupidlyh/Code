#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        c=0;
        d=a*b;
        do
        {
            c=a%b;
            a=b;
            b=c;
        }
        while(c!=0);
        printf("%d\n",d/a);
    }
    return 0;
}
