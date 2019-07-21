#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int arr[20]= {0};
    while(scanf("%d",&arr[0]))
    {
        int i;
        if(arr[0]==-1)
            break;
        else
        {
            for(i=1; arr[i-1]!=0; i++)
                scanf("%d",&arr[i]);
        }
        int num=0,j,k;
        for(k=0; k<i-1; k++)
        {
            for(j=0; j<i-1; j++)
            {
                if(k==j)
                    continue;
                if(2*arr[j]==arr[k])
                    num++;
            }
        }
        printf("%d\n",num);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
