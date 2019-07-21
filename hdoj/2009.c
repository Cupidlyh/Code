#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double n,m,sum,j;
    int i;
    while(scanf("%lf%lf",&n,&m)!=EOF)
    {sum=n;
    j=n;
    for(i=2;i<=m;i++)
    {j=sqrt(j);
    sum=sum+j;
    }
    printf("%.2lf\n",sum);
    }
    return 0;
}
