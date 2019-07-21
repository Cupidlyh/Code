#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,i,a,b;
    while(scanf("%d",&a)!=EOF)
    {sum=0;
    for(i=1;i<=a;i++)
        {scanf("%d",&b);
        sum=sum+b;
    }
    printf("%d\n",sum);
    }
    return 0;
}
