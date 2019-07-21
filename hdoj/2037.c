#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j,k,num;
    int a[100][2],temp[2];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d %d",&a[i][0],&a[i][1]);
        for(i=0; i<n-1; i++)
        {

            for(j=i+1; j<n; j++)
            {
                if(a[i][1]>a[j][1])
                {
                    temp[0]=a[i][0];
                    temp[1]=a[i][1];
                    a[i][0]=a[j][0];
                    a[i][1]=a[j][1];
                    a[j][0]=temp[0];
                    a[j][1]=temp[1];
                }
            }
        }
        k=1;
        num=a[0][1];
        for(i=1; i<n; i++)
        {
            if(a[i][0]>=num)
            {
                k++;
                num=a[i][1];
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
