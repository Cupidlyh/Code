#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(j=1000; j<=9999; j++)
        {
            if(j%a==0&&(j+1)%b==0&&(j+2)%c==0)
            {
                printf("%d\n",j);
                break;
            }
        }
        if(j>=10000)
            printf("Impossible\n");
    }
    return 0;
}
