#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char s[25];
    int b;
    int z[12];
};

struct studentt
{
    char d[25];
    int score;
};

int cmp(const void *a,const void *b)
{
    struct studentt *x=(struct studentt*) a;
    struct studentt *y=(struct studentt*) b;
    return y->score-x->score;
}

int main()
{
    int n,m,g,a[15];
    while(scanf("%d %d %d",&n,&m,&g))
    {
        if(n==0)
            break;
        struct student pt[1005];
        struct studentt ptt[1005];
        int i,j,num=0,sum;
        char sl[25];
        for(i=1; i<=m; i++)
            scanf("%d",&a[i]);

        for(i=1; i<=n; i++)
        {
            scanf("%s %d",pt[i].s,&pt[i].b);
            for(j=1; j<=pt[i].b; j++)
                scanf("%d",&pt[i].z[j]);
        }

        for(i=1; i<=n; i++)
        {
            sum=0;
            for(j=1; j<=pt[i].b; j++)
                sum+=a[pt[i].z[j]];
            if(sum>=g)
            {
                num++;
                strcpy(ptt[num].d,pt[i].s);
                ptt[num].score=sum;
            }
        }

        printf("%d\n",num);
        qsort(ptt+1,num,sizeof(ptt[0]),cmp);
        for(i=0; i<num; i++)
        {
            for(j=i+1; j<=num; j++)
            {
                if(ptt[i].score==ptt[j].score)
                {
                    if(strcmp(ptt[i].d,ptt[j].d)>0)
                    {
                        strcpy(sl,ptt[i].d);
                        strcpy(ptt[i].d,ptt[j].d);
                        strcpy(ptt[j].d,sl);
                    }
                }
            }
        }

        for(i=1; i<=num; i++)
            printf("%s %d\n",ptt[i].d,ptt[i].score);
    }
    return 0;
}
