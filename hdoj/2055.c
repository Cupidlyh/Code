#include <stdio.h>
#include <stdlib.h>
int f(char c)
{
    int i;
    char b;
    if(c=='a')
        i=-1;
        else
        {
            b=c-1;
            i=f(b)-1;
        }
    return i;
}

int f1(char c)
{
    int i;
    char b;
    if(c=='A')
        i=1;
    else
    {
        b=c-1;
        i=f1(b)+1;
    }
    return i;
}

int main()
{
    int n,m,i,sum,j;
    char c;
    scanf("%d",&n);
    getchar();
    for(i=1; i<=n; i++)
    {
        sum=0;
        scanf("%c %d",&c,&m);
        getchar();
        if(c>='a'&&c<='z')
        {
            j=f(c);
            sum=m+j;
        }
        if(c>='A'&&c<='Z')
        {
            j=f1(c);
            sum=m+j;
        }
        printf("%d\n",sum);
    }
    return 0;
}
