#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=1; j<=m*3; j++)
        {
            for(k=0; k<m; k++)
                printf("HDU");
            printf("\n");
        }
    }
    return 0;
}
