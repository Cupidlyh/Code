#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define MAXN 5005

int father[MAXN];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        father[i] = i;
}

int Find(int x)
{
    if (x == father[x])
        return x;
    else
        return Find(father[x]);
}

void Union(int x, int y)
{
    father[Find(x)] = Find(y);
}


int main()
{
    int n,m,p;
    int Mi,Mj;
    int Pi,Pj;
    while (scanf("%d %d %d",&n,&m,&p) != EOF)
    {
        init(n);
        while (m--)
        {
            scanf("%d %d",&Mi,&Mj);
            Union(Mi,Mj);
        }
        while (p--)
        {
            scanf("%d %d",&Pi,&Pj);
            if (Find(Pi) == Find(Pj))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
