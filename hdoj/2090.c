#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[50];
    double n,m,s=0.0;
    while(scanf("%s",a)!=EOF)
    {
        scanf("%lf %lf",&m,&n);
        s=s+m*n;
    }
    printf("%.1lf\n",s);
    return 0;
}
