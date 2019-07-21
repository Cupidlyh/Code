#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415927
int main()
{double a,b;
while(scanf("%lf",&a)!=EOF)
{
    b=(4.0/3.0)*PI*a*a*a;
    printf("%.3f\n",b);
}
    return 0;
}
