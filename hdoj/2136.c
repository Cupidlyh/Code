#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b[1000005];
void is_prime()
{
    int i,j,k=1;
    for(i=2; i<1000000; i++)
    {
        if(b[i]==0)
        {
            b[i]=k++;
            j=2*i;
            while(j<1000000)
            {
                b[j]=b[i];
                j=j+i;
            }
        }
    }
}

int main()
{
    int n;
    memset(b,0,sizeof(b));
    is_prime();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",b[n]);
    }
    return 0;
}
