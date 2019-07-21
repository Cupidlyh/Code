#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sum=0.0,aver=0.0;
    double a[12];
    int i;
    for(i=0;i<12;i++)
        scanf("%lf",&a[i]);
    for(i=0;i<12;i++)
        sum=sum+a[i];
    aver=sum/12.0;
    printf("$%.2f\n",aver);
    return 0;
}
