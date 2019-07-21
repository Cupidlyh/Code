#include<stdio.h>
#include<stdlib.h>
int n;
int a[25];
int color[25];
int parent[25];

void print()
{
    for(int i=1; i<n; i++)
    {
        printf("%d ",parent[i]);
    }
    printf("%d\n",parent[n]);
}

int isPrime(int num)
{
    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int u, int count)
{
    count++;
    //�ݹ�蹵
    if(count==n && isPrime(a[u]+a[1]))
    {
        //�ҵ�һ�����
        parent[count] = a[u];
        print();//���
        return;//����
    }
    color[u]=1; //��ʾ�Ѿ�����,��ɫ
    //����u�������ھӽڵ�
    for(int v=1; v<=n; v++)
    {
        if( color[v]==-1 && isPrime(a[u]+a[v]) )
        {
            //�ҵ�һ�����������Ľڵ�
            parent[count] = a[u];//��¼�ϼ��ڵ�
            dfs(v,count);
            color[v]=-1; //��v��ԭ��δ����״̬�����ú���·���ܹ����Է���
        }
    }
}

int main()
{
    int k=0;
    while( ~scanf("%d",&n))
    {
        printf("Case %d:\n",(++k) );
        //��ʼ��ͼ
        for(int i=1; i<=n; i++ )
        {
            a[i] = i;
            color[i] = -1; //��ɫ--δ����
            parent[i] = -1; //�ϼ��ڵ�
        }
        int count=0; //time, �������Ľڵ����
        dfs(1,count);
        printf("\n");
    }
    return 0;
}
