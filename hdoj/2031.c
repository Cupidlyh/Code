#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,m;
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        if(n<0)
            m=-n;
        else
            m=n;
        char arr[1000]= {'0'};
        int i=0,k,j;
        while(m!=0)
        {
            k=m%r;
            if(k<10)
                arr[i++]=k+'0';
            if(k==10)
                arr[i++]='A';
            if(k==11)
                arr[i++]='B';
            if(k==12)
                arr[i++]='C';
            if(k==13)
                arr[i++]='D';
            if(k==14)
                arr[i++]='E';
            if(k==15)
                arr[i++]='F';
            m=m/r;
        }
        if(n<0)
            printf("-");
        for(j=i-1; j>=0; j--)
            printf("%c",arr[j]);
        printf("\n");
    }
    return 0;
}

