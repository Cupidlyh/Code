#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[10000];
    char b[100][100];
    int c[100];
    int flag,k,n,i,j;
    while(gets(a)!=NULL)
    {
        if(a[0]=='#')
            break;
        flag=1;
        k=-1;
        n=0;
        i=0;
        j=0;
        memset(c,0,sizeof(c));
        while(a[i]!='\0')
        {
            if(a[i]==' ')
            {
                flag=1;
            }
            else
            {
                if(flag==1)
                {
                    if(k>=0)
                        b[k][n]='\0';
                    k++;
                    flag=0;
                    n=0;
                }
                if(a[i]!=' ')
                    b[k][n++]=a[i];
            }
            i++;
        }
        b[k][n]='\0';
        for(i=0; i<k+1; i++)
            for(j=i+1; j<k+1; j++)
            {
                if(strcmp(b[i],b[j])==0)
                {
                    c[j]=1;
                }
            }
        int num=0;
        for(i=0; i<k+1; i++)
            if(c[i]==0)
                num++;
        printf("%d\n",num);

    }
    return 0;
}
