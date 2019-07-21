#include <stdio.h>
#include <stdlib.h>

int main()
{   void bj(float a,float b,float c);
    int m,i;
    float x[1000],y[1000],z[1000];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%f%f%f",&x[i],&y[i],&z[i]);
        for(i=1;i<=m;i++)
        bj(x[i],y[i],z[i]);
    return 0;
}


void bj(float a,float b,float c)
{
    int leap;
    if(a+b>c&&a+c>b)
        leap=1;
    else
        leap=0;
    if(leap==1&&b+c>a)
        printf("YES\n");
    else
        printf("NO\n");
}
