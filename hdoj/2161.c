#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i,flag,n,flag1,m=0;
    while(scanf("%d",&n))
    {
        if(n<=0)
            break;
        m++;
        flag=0;
        flag1=0;
        if(n==1||n==2)
            printf("%d: no\n",m);
        else
        {
            for(i=2; i<=sqrt(n); i++)
            {
                if(n%i==0)
                {
                    flag1=1;
                    break;
                }
            }
            if(flag1==0)
                flag=1;
            if(flag==1)
                printf("%d: yes\n",m);
            else
                printf("%d: no\n",m);
        }
    }
    return 0;
}
