#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        c=a+b;
        if(c%86==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
