#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,k,l,a[50][2],temp[2],p,q,r;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=0; j<m; j++)
            scanf("%d%d",&a[j][0],&a[j][1]);
        for(p=0; p<m-1; p++)
        {

            for(q=p+1; q<m; q++)
            {
                if(a[p][0]>a[q][0])
                {
                    temp[0]=a[p][0];
                    temp[1]=a[p][1];
                    a[p][0]=a[q][0];
                    a[p][1]=a[q][1];
                    a[q][0]=temp[0];
                    a[q][1]=temp[1];
                }
            }
        }
        for(r=0; r<m; r++)
        {
            for(k=0; k<a[r][1]; k++)
            {
                printf(">+");
                for(l=0; l<a[r][0]-2; l++)
                    printf("-");
                printf("+>\n");
            }
            printf("\n");
        }
    }
    return 0;
}
