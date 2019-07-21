#include <stdio.h>
#include <stdlib.h>

struct node
{
    int w,s;
    int sum;
} p[100002];

/*int cmp(const void *a,const void *b)//比较器写法1
{
    struct node *x=(struct node*) a;
    struct node *y=(struct node*) b;
    return y->sum-x->sum;
}*/

/*int cmp(struct node *a,struct node *b)//比较器写法2
{
    return b->sum-a->sum;
}*/


int cmp(struct node a,struct node b)/*比较器写法3,注意这种写法需要选择语言是GCC*/
{
    return b.sum-a.sum;
}

int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        __int64 s=0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&p[i].w,&p[i].s);
            p[i].sum=p[i].s+p[i].w;
            s=s+p[i].w;
        }
        qsort(p,n,sizeof(p[0]),cmp);
        __int64 a=0,b;
        for(i=0; i<n; i++)
        {
            s=s-p[i].w;
            b=s-p[i].s;
            if(b>0)
                a=a>b?a:b;
        }
        printf("%I64d\n",a);
    }
    return 0;
}
