#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,b,s;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&a,&b);
        s=0;
        a=a%100;
        b=b%100;
        s=(a+b)%100;
        printf("%d\n",s);
    }
    return 0;
}
