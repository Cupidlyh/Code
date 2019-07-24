#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int ans=1;
        while(b!=0)
        {
            if(b%2==1)
                ans=((ans%10)*(a%10))%10;
            a=((a%10)*(a%10))%10;
            b=b/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
