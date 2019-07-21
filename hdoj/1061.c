#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[1000000];

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {

        while(t--)
        {
            int n;
            memset(arr,0,sizeof(arr));
            scanf("%d",&n);
            int k=n%10,i,flag=0;
            arr[1]=k;
            for(i=2; i<=n; i++)
            {
                k=k*n;
                k=k%10;
                arr[i]=k;
                if(arr[i]==arr[1])
                {
                    arr[0]=arr[i-1];
                    flag=1;
                    break;
                }
            }
            if(flag==1&&i-1!=1)
                printf("%d\n",arr[n%(i-1)]);
            else
                printf("%d\n",k);
        }
    }
    return 0;
}
