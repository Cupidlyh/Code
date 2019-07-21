#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,a[100],i,j,k,temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=0; j<m; j++)
            scanf("%d",&a[j]);
        for(j=0; j<m-1; j++)
            for(k=j+1; k<m; k++)
                if(a[k]<a[j])
                {
                    temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                }
        printf("%d\n",a[1]);
    }
    return 0;
}
