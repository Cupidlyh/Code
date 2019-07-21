#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{double a,b,c,d,e;
while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
{
    e=sqrt((c-a)*(c-a)+(d-b)*(d-b));
    printf("%.2f\n",e);
}
    return 0;
}
