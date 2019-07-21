#include <stdio.h>
#include <stdlib.h>

int f(int A,int B,int n)
{
    int m;
    if(n==1||n==2)
        m=1;
    else
    {
        m=(A * f(A,B,n - 1) + B * f(A,B,n - 2))%7;
    }
    return m;
}

int main()
{
    int A,B,n,m;
    scanf("%d%d%d",&A,&B,&n);
    while(A!=0)
    {
        n=n%49;
        m=f(A,B,n);
        printf("%d\n",m);
        scanf("%d%d%d",&A,&B,&n);
    }
    return 0;
}
