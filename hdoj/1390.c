#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d;
    while(scanf("%d",&d)!=EOF)
    {
        while(d--)
        {
            int n,i=0,j,arr[10000]= {0},flag=0;
            scanf("%d",&n);
            while(n)
            {
                arr[i++]=n%2;
                n=n/2;
            }
            for(j=0; j<i; j++)
            {
                if(flag==0&&arr[j]==1)
                {
                    flag=1;
                    printf("%d",j);
                    continue;
                }
                if(flag==1&&arr[j]==1)
                    printf(" %d",j);
            }
            printf("\n");
        }
    }
    return 0;
}
