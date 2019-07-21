#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        m=1;
        j=1;
        while(m<k)
        {
            j++;
            m=m+j*j*j;
        }
        printf("%d\n",j);
    }
    return 0;
}
