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
#define MAXN 2005

int father[MAXN];
int relat[MAXN];

int Find(int x)
{
    if (x != father[x])
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        relat[x] = (relat[x] + relat[temp]) % 2;
    }
    return father[x];
}


int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    int num = 1;
    while (T--)
    {
        scanf("%d %d",&n,&m);
        for (int i = 0; i <= n; i++)
        {
            father[i] = i;
            relat[i] = 0;
        }
        int x,y;
        int flag = 0;
        while(m--)
        {
            scanf("%d %d",&x,&y);
            if (flag)
                continue;
            int rx = Find(x);
            int ry = Find(y);
            if (rx == ry)
            {
                if (relat[x] == relat[y])
                    flag = 1;
            }
            else
            {
                father[ry] = rx;
                relat[ry] = (1 + relat[x] - relat[y]) % 2;
            }
        }
        printf("Scenario #%d:\n",num++);
        if(!flag)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }

    return 0;
}
