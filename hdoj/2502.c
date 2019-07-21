#include <stdio.h>
#include <stdlib.h>
#define MAX 1100000
int z[MAX+5],x[MAX+5];
int m,n,u=1,v=1;
int main()
{
    int p,i,f,flag,j,o,y,c;
    for(i=1; i<=MAX; i++)
    {
        n=0;
        m=0;
        y=i;
        while(y)
        {
            c=y;
            y=y%2;
            n++;
            if(y==1)
                m++;
            y=c/2;
        }
    }
    z[u++]=n;/*二进制位数*/
    x[v++]=m;/*1的个数*/
    scanf("%d",&p);
    for(i=0; i<p; i++)
    {
        scanf("%d",&f);
        flag=0;
        o=1;
        while(z[o]!=f)
            o++;
        for(j=o; j<=MAX; j++)
        {
            flag=flag+x[j];
            if(z[j+1]!=f)
                break;
        }
        printf("%d\n",flag);
    }
    return 0;
}
