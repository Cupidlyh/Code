#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4],i,j,temp,z=0;
    while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]))
    {
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)
            break;
        if(z!=0)
            printf("\n");
        z++;
        for(i=0; i<3; i++)
        {
            for(j=i+1; j<4; j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        if(a[0]==0&&a[1]!=0&&a[2]!=0&&a[3]!=0)
        {
            if(a[1]!=a[2]&&a[2]!=a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[1],a[0],a[2],a[3],a[1],a[0],a[3],a[2],a[1],a[2],a[0],a[3],a[1],a[2],a[3],a[0],a[1],a[3],a[0],a[2],a[1],a[3],a[2],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[2],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2],a[1],a[0],a[3],a[2],a[1],a[3],a[0],a[2],a[3],a[0],a[1],a[2],a[3],a[1],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[3],a[0],a[1],a[2],a[3],a[0],a[2],a[1],a[3],a[1],a[0],a[2],a[3],a[1],a[2],a[0],a[3],a[2],a[0],a[1],a[3],a[2],a[1],a[0]);
            }
            if(a[1]==a[2]&&a[2]==a[3])
            {
                printf("%d0%d%d %d%d0%d %d%d%d0\n",a[1],a[2],a[3],a[1],a[2],a[3],a[1],a[2],a[3]);
            }
            if(a[1]==a[2]&&a[2]!=a[3])
            {
                printf("%d0%d%d %d0%d%d %d%d0%d %d%d%d0 %d%d0%d %d%d%d0\n",a[1],a[2],a[3],a[1],a[3],a[2],a[1],a[2],a[3],a[1],a[2],a[3],a[1],a[3],a[2],a[1],a[3],a[2]);
                printf("%d0%d%d %d%d0%d %d%d%d0\n",a[3],a[1],a[2],a[3],a[1],a[2],a[3],a[1],a[2]);
            }
            if(a[1]!=a[2]&&a[2]==a[3])
            {
                printf("%d0%d%d %d%d0%d %d%d%d0\n",a[1],a[2],a[3],a[1],a[2],a[3],a[1],a[2],a[3]);
                printf("%d0%d%d %d0%d%d %d%d0%d %d%d%d0 %d%d0%d %d%d%d0\n",a[3],a[1],a[2],a[3],a[2],a[1],a[3],a[1],a[2],a[3],a[1],a[2],a[3],a[2],a[1],a[3],a[2],a[1]);
            }
        }

        if(a[0]==0&&a[1]==0&&a[2]!=0&&a[3]!=0)
        {
            if(a[2]!=a[3])
            {
                printf("%d00%d %d0%d0 %d%d00\n",a[2],a[3],a[2],a[3],a[2],a[3]);
                printf("%d00%d %d0%d0 %d%d00\n",a[3],a[2],a[3],a[2],a[3],a[2]);
            }
            if(a[2]==a[3])
            {
                printf("%d00%d %d0%d0 %d%d00\n",a[2],a[3],a[2],a[3],a[2],a[3]);
            }
        }

        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]!=0)
        {
            printf("%d000\n",a[3]);
        }

        if(a[0]!=0&&a[1]!=0&&a[2]!=0&&a[3]!=0)
        {
            if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]!=a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[1],a[3],a[2],a[0],a[2],a[1],a[3],a[0],a[2],a[3],a[1],a[0],a[3],a[1],a[2],a[0],a[3],a[2],a[1]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[1],a[0],a[2],a[3],a[1],a[0],a[3],a[2],a[1],a[2],a[0],a[3],a[1],a[2],a[3],a[0],a[1],a[3],a[0],a[2],a[1],a[3],a[2],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[2],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2],a[1],a[0],a[3],a[2],a[1],a[3],a[0],a[2],a[3],a[0],a[1],a[2],a[3],a[1],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[3],a[0],a[1],a[2],a[3],a[0],a[2],a[1],a[3],a[1],a[0],a[2],a[3],a[1],a[2],a[0],a[3],a[2],a[0],a[1],a[3],a[2],a[1],a[0]);
            }
            if(a[0]==a[1]&&a[1]!=a[2]&&a[2]!=a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[1],a[3],a[2],a[0],a[2],a[1],a[3],a[0],a[2],a[3],a[1],a[0],a[3],a[1],a[2],a[0],a[3],a[2],a[1]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[2],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2],a[3],a[0],a[1]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[3],a[0],a[1],a[2],a[3],a[0],a[2],a[1],a[3],a[2],a[0],a[1]);
            }
            if(a[0]!=a[1]&&a[1]==a[2]&&a[2]!=a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[1],a[0],a[2],a[3],a[1],a[0],a[3],a[2],a[1],a[2],a[0],a[3],a[1],a[2],a[3],a[0],a[1],a[3],a[0],a[2],a[1],a[3],a[2],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[3],a[0],a[1],a[2],a[3],a[1],a[0],a[2],a[3],a[1],a[2],a[0]);
            }
            if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]==a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[2],a[1],a[3],a[0],a[2],a[3],a[1]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[1],a[0],a[2],a[3],a[1],a[2],a[0],a[3],a[1],a[2],a[3],a[0]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n",a[2],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2],a[1],a[0],a[3],a[2],a[1],a[3],a[0],a[2],a[3],a[0],a[1],a[2],a[3],a[1],a[0]);
            }
            if(a[0]==a[1]&&a[2]==a[3]&&a[1]!=a[2])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[2],a[1],a[3],a[0],a[2],a[3],a[1]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[2],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2],a[3],a[0],a[1]);
            }
            if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3])
            {
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[0],a[1],a[2],a[3],a[0],a[1],a[3],a[2],a[0],a[3],a[1],a[2]);
                printf("%d%d%d%d\n",a[3],a[0],a[1],a[2]);
            }
            if(a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3])
            {
                printf("%d%d%d%d\n",a[0],a[1],a[2],a[3]);
                printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",a[1],a[0],a[2],a[3],a[1],a[2],a[0],a[3],a[1],a[2],a[3],a[0]);
            }
            if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
            {
                printf("%d%d%d%d\n",a[0],a[1],a[2],a[3]);
            }
        }
    }
    return 0;
}
