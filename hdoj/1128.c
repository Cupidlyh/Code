#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000005
int hash[MAX];

void fun(int n)
{
    int sum=n;
    while(n)
    {
        sum=sum+n%10;
        n=n/10;
    }
    hash[sum]=1;
}

int main()
{
    memset(hash,0,sizeof(hash));
    int i;
    for(i=1; i<MAX; i++)
        fun(i);
    for(i=1; i<MAX; i++)
        if(hash[i]==0)
            printf("%d\n",i);
    return 0;
}
