#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int t,i,temp=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&t);
            temp=temp^t;
        }
        printf("%d\n",temp);
    }
    return 0;
}
