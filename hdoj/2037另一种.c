#include <stdio.h>
#include <stdlib.h>
struct time
{
    int start;
    int end;
} record[100];

int cmp(const void *a,const void *b)//比较器
{
    struct time *x=(struct time*) a;
    struct time *y=(struct time*) b;
    return x->end-y->end;
}

int main()
{
    int i,n,count,lastend;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%d %d",&record[i].start,&record[i].end);
        qsort(record,n,sizeof(record[0]),cmp);//调用这个函数进行排序，这个只能用在结构体中，本例中是从小到大排序
        count=0;
        lastend=-1;
        for(i=0; i<n; i++)
        {
            if(record[i].start>=lastend)
            {
                count++;
                lastend=record[i].end;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
