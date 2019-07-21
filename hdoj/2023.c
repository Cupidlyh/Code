#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k,sum,flag;
    int a[50][5];
    double b[50],c[50];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        for(i=0; i<n; i++)
        {
            sum=0;
            for(j=0; j<m; j++)
            {
                sum=sum+a[i][j];
            }
            b[i]=sum/(double)m;
        }
        for(i=0; i<m; i++)
        {
            sum=0;
            for(j=0; j<n; j++)
            {
                sum=sum+a[j][i];
            }
            c[i]=sum/(double)n;
        }
        k=0;
        flag=0;
        for(i=0; i<n; i++)
        {

            for(j=0; j<m; j++)
            {
                if(a[i][j]>=c[j])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                k++;
        }
        for(i=0; i<n; i++)
            if(i!=n-1)
                printf("%.2f ",b[i]);
            else
                printf("%.2f\n",b[i]);
        for(i=0; i<m; i++)
            if(i!=m-1)
                printf("%.2f ",c[i]);
            else
                printf("%.2f\n",c[i]);
        printf("%d\n\n",k);
    }
    return 0;
}
