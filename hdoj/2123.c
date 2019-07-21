#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,m,n;
    scanf("%d",&m);
    for(k=1; k<=m; k++)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(j==n)
                    printf("%d\n",i*j);
                else
                    printf("%d ",i*j);
            }
        }
    }

    return 0;
}
