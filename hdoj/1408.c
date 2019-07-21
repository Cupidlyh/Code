#include <stdio.h>
#include <stdlib.h>

int main()
{
    double vul,d;
    int n,k;
    while(scanf("%lf%lf",&vul,&d)!=EOF)
    {
           n=vul/d;
           if(vul-n*d>0.000001)
           n=n+1;
           k=1;
           while(vul>0.000001)
           {
               vul=vul-d*k;
               k++;
           }
           printf("%d\n",n+k-2);
    }
    return 0;
}
