#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int n,m,ans=1;
            scanf("%d",&n);
            m=n;
            while(n!=0)
            {
                if(n%2==1)
                    ans=((ans%10)*(m%10))%10;
                m=((m%10)*(m%10))%10;
                n=n/2;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
