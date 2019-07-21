#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1||n%2==0)
            printf("2^? mod %d = 1\n",n);
        else
        {
            int k=1;
            for(int x=1;; x++)
            {
                k=k%n*2;
                if(k%n==1)
                {
                    printf("2^%d mod %d = 1\n",x,n);
                    break;
                }
            }
        }
    }
    return 0;
}
