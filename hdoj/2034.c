#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,k;
    int flag,temp;
    int a[100],b[100],c[100];
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        flag=1;
        k=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<m; i++)
            scanf("%d",&b[i]);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i]!=b[j])
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                c[k]=a[i];
                k++;
            }
        }
        if(k==0)
            printf("NULL\n");
        if(k>0)
        {
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
                    printf("%d \n",c[i]);
        }

    }
    return 0;
}
