#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int k=a%10,i,arr[10000]= {0},flag=0;
        arr[1]=k;
        for(i=2; i<=b; i++)
        {
            k=k*a;
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
            printf("%d\n",arr[b%(i-1)]);
        else
            printf("%d\n",k);
    }
    return 0;
}
