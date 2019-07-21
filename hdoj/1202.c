#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double a[105]= {0},b[105]= {0},c[105]= {0},d[105]= {0},score=0,score1=0;
        int i;
        for(i=1; i<=n; i++)
        {
            scanf("%lf %lf",&a[i],&b[i]);
            if(b[i]>=90)
                c[i]=4;
            else if(b[i]>=80)
                c[i]=3;
            else if(b[i]>=70)
                c[i]=2;
            else if(b[i]>=60)
                c[i]=1;
            else if(b[i]>=0)
                c[i]=0;
            else
                c[i]=-1;
            d[i]=a[i]*c[i];
            if(b[i]!=-1)
            {
                score=score+a[i];
                score1=score1+d[i];
            }
        }
        if(score==0)
            printf("-1\n");
        else
            printf("%.2lf\n",score1/score);
    }
    return 0;
}
