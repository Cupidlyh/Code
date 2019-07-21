#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,z;
    while(scanf("%d %d",&a,&b))
    {
        z=0;
        if(a==0&&b==0)
            break;
        for(i=a*100; i<=a*100+99; i++)
        {
            if(i%b==0)
            {
                if(z==0)
                    printf("%02d",i-a*100);
                else
                    printf(" %02d",i-a*100);
                z++;
            }
        }
        printf("\n");
    }
    return 0;
}
