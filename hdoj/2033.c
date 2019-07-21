#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,c,d,e,f,n,x,y;
    int z[3];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        x=0;
        y=0;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if(c+f<60)
            z[2]=c+f;
        else
        {
            x=(c+f)/60;
            z[2]=(c+f)%60;
        }
        y=b+e+x;
        if(y<60)
            z[1]=y;
        else
        {
            x=y/60;
            z[1]=y%60;
        }
        z[0]=a+d+x;
        printf("%d %d %d\n",z[0],z[1],z[2]);
    }
    return 0;
}
