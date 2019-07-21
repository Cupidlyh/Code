#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        if(a%b==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
