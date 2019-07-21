#include <stdio.h>
#include <stdlib.h>
int main()
{double a,b;
while(scanf("%lf",&a)!=EOF)
{   b=-1*a;
    if(a>=0)
    printf("%.2f\n",a);
    else
        printf("%.2f\n",b);
}
    return 0;
}
