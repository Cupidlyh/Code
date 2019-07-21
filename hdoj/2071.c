#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,m;
    double max,a[100];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=0; j<m; j++)
            scanf("%lf",&a[j]);
        max=a[0];
        for(j=0; j<m; j++)
            if(max<a[j])
                max=a[j];
        printf("%.2f\n",max);
    }
    return 0;
}
