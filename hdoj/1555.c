#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,k;
    while(scanf("%d %d",&m,&k))
    {
        if(m==0&&k==0)
            break;
        int day=0;
        while(m)
        {
            m--;
            day++;
            if(day%k==0)
                m++;
        }
        printf("%d\n",day);
    }
    return 0;
}
