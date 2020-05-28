#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    map<string,int> mp;
    int m,n,i,money;
    string s;
    char c;
    scanf("%d %d",&m,&n);
    for(i = 0; i < m; i++)
    {
        cin>>s>>money;
        mp[s] = money;
    }
    s = "";
    for(i = 0; i < n; i++)
    {
        money = 0;
        while(scanf("%c",&c) != EOF)
        {
            if(c == ' ' || c == '.' || c == '\n')
            {
                if(mp.find(s) != mp.end())
                    money += mp[s];
                s = "";
            }
            else
            {
                s += c;
            }
            if(c == '.')
                break;
        }
        printf("%d\n",money);
    }
    return 0;
}
