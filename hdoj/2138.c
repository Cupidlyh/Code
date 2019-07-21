#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,a[1000]= {0},flag=1,num=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
        {
            flag=1;
            for(j=2; j<=sqrt(a[i]); j++)
                if(a[i]%j==0)
                {
                    flag=0;
                    break;
                }
            if(flag==1)
                num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
