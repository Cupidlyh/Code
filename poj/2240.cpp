#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

//记录每种钱的编号
map<string,int> mp;
//记录i到j编号钱的汇率
double len[1005][1005];

void floyd(int n)
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(len[i][j] < len[i][k] * len[k][j])//从i经k到j的钱数换的更多
                {
                    len[i][j] = len[i][k] * len[k][j];//更新len[i][j]
                }
}

int main()
{
    int n,m;
    double z;
    string s1,s2;
    int cas = 1;
    int bit;
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0)
            break;
        mp.clear();
        bit = 1;
        for (int i = 0; i < n; i++)
        {
            cin>>s1;
            mp[s1] = bit++;
        }
        scanf("%d",&m);
        memset(len,0,sizeof(len));
        for (int i = 0; i < m; i++)
        {
            cin>>s1>>z>>s2;
            len[mp[s1]][mp[s2]] = z;
        }
        floyd(n);
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (len[i][i] > 1)
            {
                flag = 0;
                printf("Case %d: Yes\n",cas++);
                break;
            }
        }
        if (flag)
            printf("Case %d: No\n",cas++);

    }
    return 0;
}
