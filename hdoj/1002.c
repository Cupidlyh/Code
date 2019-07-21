#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k,m,o,p,q,r,t,u,v,x,y,z;
    char a[1000],b[1000],c[1000],d,e,f,g[1000],h[1000];
    scanf("%d",&t);
    for(p=1; p<=t; p++)
    {
        k=0;
        r=0;
        scanf("%s %s",a,b);
        strcpy(g,a);
        strcpy(h,b);
        u=m=strlen(a);
        v=q=strlen(b);
        if(m>=q)
        {
            for(j=m; j>=1; j--)
                a[j]=a[j-1];
            a[0]='0';
            a[m+1]='\0';
            for(j=q-1; j>=0; j--)
            {
                b[u]=b[j];
                u--;
            }
            for(u=0; u<=m-q; u++)
                b[u]='0';
            b[m+1]='\0';
            for(j=m; j>=0; j--)
            {

                if(k==0)
                {
                    e=a[j];
                    f=b[j];
                    x=((int)e)-48;
                    y=((int)f)-48;
                    z=x+y;
                    if(z>=10)
                    {
                        c[r]=(char)(z%10+48);
                        k=1;
                        r++;
                        continue;
                    }
                    else
                    {
                        c[r]=(char)(z%10+48);
                        k=0;
                        r++;
                    }
                }
                if(k==1)
                {
                    e=a[j];
                    f=b[j];
                    x=((int)e)-48;
                    y=((int)f)-48;
                    z=x+y+1;
                    if(z>=10)
                    {
                        c[r]=(char)(z%10+48);
                        k=1;
                        r++;
                        continue;
                    }
                    else
                    {
                        c[r]=(char)(z%10+48);
                        k=0;
                        r++;
                    }
                }

            }
        }
        if(m<q)
        {
            for(j=q; j>=1; j--)
                b[j]=b[j-1];
            b[0]='0';
            b[q+1]='\0';
            for(j=m-1; j>=0; j--)
            {
                a[v]=a[j];
                v--;
            }
            for(v=0; v<=q-m; v++)
                a[v]='0';
            a[q+1]='\0';
            for(j=q; j>=0; j--)
            {

                if(k==0)
                {
                    e=a[j];
                    f=b[j];
                    x=((int)e)-48;
                    y=((int)f)-48;
                    z=x+y;
                    if(z>=10)
                    {
                        c[r]=(char)(z%10+48);
                        k=1;
                        r++;
                        continue;
                    }
                    else
                    {
                        c[r]=(char)(z%10+48);
                        k=0;
                        r++;
                    }
                }
                if(k==1)
                {
                    e=a[j];
                    f=b[j];
                    x=((int)e)-48;
                    y=((int)f)-48;
                    z=x+y+1;
                    if(z>=10)
                    {
                        c[r]=(char)(z%10+48);
                        k=1;
                        r++;
                        continue;
                    }
                    else
                    {
                        c[r]=(char)(z%10+48);
                        k=0;
                        r++;
                    }
                }

            }
        }
        c[r]='\0';
        o=strlen(c);
        for(i=0; i<o/2; i++)
        {
            d=c[i];
            c[i]=c[o-i-1];
            c[o-i-1]=d;
        }
        c[o]='\0';
        if(c[0]=='0')
        {
            for(i=0; i<o-1; i++)
                c[i]=c[i+1];
            c[o-1]='\0';
        }
        if(p!=t)
        {
            printf("Case %d:\n",p);
            printf("%s + %s = %s\n\n",g,h,c);
        }
        else
        {
            printf("Case %d:\n",p);
            printf("%s + %s = %s\n",g,h,c);
        }
    }
    return 0;
}
