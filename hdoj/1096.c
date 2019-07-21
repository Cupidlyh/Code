#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,i,j,a,b,c;
    scanf("%d",&c);
    for(j=1;j<=c;j++)
     {scanf("%d",&a);
    sum=0;
    for(i=1;i<=a;i++)
        {scanf("%d",&b);
        sum=sum+b;
    }
    if(j<c)
    printf("%d\n\n",sum);
    if(j==c)
         printf("%d\n",sum);
     }
    return 0;
}
