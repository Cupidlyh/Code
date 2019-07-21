#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,t;
    double a[21],b[21];
    double s;
    a[1]=0;
    a[2]=1;
    a[3]=2;
    for(i=4;i<=20;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    b[1]=1;
    b[0]=1;
    for(i=2;i<=20;i++)
        b[i]=i*b[i-1];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&t);
       s=a[t]/b[t];
       s=s*100;
       printf("%.2lf",s);
       printf("%c\n",'%');
    }
    return 0;
}
