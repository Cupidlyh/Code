#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int d;
    while(scanf("%d",&d)!=EOF)
    {
        while(d--)
        {
            int n,i;
            scanf("%d",&n);
            for(i=0;; i++)
            {
                if(n%((int)pow(2,i))==0)
                    if((n/((int)pow(2,i)))%2==1)
                    {
                        printf("%d %d\n",n/((int)pow(2,i)),i);
                        break;
                    }
            }
        }
    }
    return 0;
}
