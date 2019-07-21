#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k,flag,temp;
    int a[10000],b[10000],c[10000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        k=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<m; i++)
            scanf("%d",&b[i]);
        for(i=0; i<n; i++)
        {
            c[k]=a[i];
            k++;
        }
        for(j=0; j<m; j++)
        {
            flag=0;
            for(i=0; i<n; i++)
                if(b[j]!=a[i])
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            if(flag==1)
            {
                c[k]=b[j];
                k++;
            }
        }
        for(i=0; i<k-1; i++)
            for(j=i+1; j<k; j++)
                if(c[i]>c[j])
                {
                    temp=c[i];
                    c[i]=c[j];
                    c[j]=temp;
                }
        for(i=0; i<k; i++)
            if(i!=k-1)
                printf("%d ",c[i]);
            else
                printf("%d\n",c[i]);
    }
    return 0;
}
