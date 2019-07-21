#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//素数筛选模板1：标记数组

int prime[20001];//标记数组
int max_prime[20001];
int a[20001];
int b[20001];
void is_prime()
{
    prime[0]=0;
    prime[1]=0;
    int i,j;
    for(i=2; i*i<=20000; i++)
    {
        if(prime[i])
        {
            j=2*i;
            while(j<=20000)
            {
                prime[j]=0;
                j=j+i;
            }
        }
    }
}

void is_max_prime()
{
    max_prime[0]=0;
    max_prime[0]=1;
    int i,j;
    for(i=2; i<=20000; i++)
        for(j=i; j>=2; j--)
            if(prime[j]&&i%j==0)
            {
                max_prime[i]=j;
                break;
            }
}

int main()
{
    int n,i;
    memset(prime,-1,sizeof(prime));
    is_prime();
    is_max_prime();
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=max_prime[a[i]];
        }
        int num=-1,res;
        for(i=0; i<n; i++)
            if(b[i]>num)
            {
                num=b[i];
                res=a[i];
            }
        printf("%d\n",res);
    }
    return 0;
}
