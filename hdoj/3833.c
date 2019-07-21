#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[10005];/*哈希算法的核心：把值转换成地址*/
int hash[10005];
int main()
{
    int t,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            hash[a[i]]=i;/*序号作为特性*/
        }
        int flag=0;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                int s=a[i]+a[j];
                if(s%2==1)
                    continue;
                if(hash[s/2]>hash[a[i]]&&hash[s/2]<hash[a[j]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        printf("%s\n",flag?"Y":"N");
        memset(hash,0,sizeof(hash));
    }
    return 0;
}
