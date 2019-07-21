#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char a[100000],b[100000];
    int i,m,n,c,d,e,f,g;
    while(scanf("%s %s",a,b)!=EOF)
    {
        m=0;
        n=0;
        e=0;
        f=0;
        c=strlen(a);
        d=strlen(b);
        while(a[m]!='.'&&a[m]!='\0')
            m++;
        while(b[n]!='.'&&b[n]!='\0')
            n++;
        if(m==c&&n>0&&n<d)
        {
            e=d-n-1;
            for(i=c; e>0; i++)
            {
                a[i]='0';
                e--;
            }
            a[i]='\0';
            for(i=n; i<d-1; i++)
                b[i]=b[i+1];
            b[i]='\0';
        }
        if(m<c&&m>0&&n==d)
        {
            e=c-m-1;
            for(i=d; e>0; i++)
            {
                b[i]='0';
                e--;
            }
            b[i]='\0';
            for(i=n; i<c-1; i++)
                a[i]=a[i+1];
            a[i]='\0';
        }
        if((m>0&&m<c)&&(n>0&&n<d))
        {
            f=d-n-1;
            e=c-m-1;
            if(e>f)
            {
                g=e-f;
                for(i=m; i<c-1; i++)
                    a[i]=a[i+1];
                a[i]='\0';
                for(i=n; i<d-1; i++)
                    b[i]=b[i+1];
                while(g>0)
                {
                    b[i]='0';
                    i++;
                    g--;
                }
                b[i]='\0';
            }
            if(e<f)
            {
                g=f-e;
                for(i=n; i<d-1; i++)
                    b[i]=b[i+1];
                b[i]='\0';
                for(i=m; i<c-1; i++)
                    a[i]=a[i+1];
                while(g>0)
                {
                    a[i]='0';
                    i++;
                    g--;
                }
                a[i]='\0';
            }

        }
        if(strcmp(a,b)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
