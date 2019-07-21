#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000010
int prime[MAX];//标记数组
int s[200];//素数表
int size=0;//素数个数
//素数筛选模板2：求出所有素数并存入一个数组中
void is_prime()
{
    prime[0]=0;
    prime[1]=0;
    int i,j;
    s[0]=2;
    for(i=2; i*2<=MAX; i++)
        prime[2*i]=0;
    for(i=3; i*i<MAX; i=i+2)
    {
        if(prime[i])
        {
            s[++size]=i;
            for(j=i*i; j<MAX; j=j+i)
                prime[j]=0;
        }
    }
}

int main()
{
    memset(prime,-1,sizeof(prime));
    is_prime();
    int n,i,z,m,t;
    scanf("%d",&t);
    for(z=0; z<t; z++)
    {
        scanf("%d",&n);
        m=n>0?n:-n;
        for(i=0; i<=size; i++)
        {
            if(prime[(s[i]+m)])
                break;
        }
        if(n>0)
            printf("%d %d\n",s[i]+m,s[i]);
        else
            printf("%d %d\n",s[i],s[i]+m);
    }
    return 0;
}
