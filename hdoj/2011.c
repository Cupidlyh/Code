#include <stdio.h>
#include <stdlib.h>

int main()
{   void sum(int z);
    int m,i;
    int a[101];
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
            sum(a[i]);
    return 0;
}

void sum(int z)
{   int sign=-1;
    double b,y,x;
    b=0;
    for(x=1.0;x<=z;x++)
    {   sign=-sign;
        y=sign/x;
        b=b+y;
    }
        printf("%.2f\n",b);
}
