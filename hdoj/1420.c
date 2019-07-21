#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,a,b,c,j;
        long long int k;
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(b==0)
                printf("%d\n",1%c);
            if(b==1)
                printf("%d\n",a%c);
            if(b>1)
            {
                k=a;
                for(j=1; j<b; j++)
                {
                    k=k*a;
                    k=k%c;
                }
                printf("%I64d\n",k);
            }
        }
    }
    return 0;
}
