#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int T;
    string s;
    int book[26];
    scanf("%d",&T);
    while(T--)
    {
        memset(book,0,sizeof(book));
        cin>>s;
        string res,temp;
        int flag = 0,i,j;
        int len = s.length();
        for(i = 0; i < len; i++)//统计AGCT四个字母出现次数
            book[s[i] - 'A']++;
        for(i = 0; i < 26; i++)
            if(book[i] != 0)//AGCT字母中找出最小先出现的字母
                break;
        for(j = 0; j < len; j++)
        {
            if(s[j] - 'A' == i)//用最小的字母组成字符串
            {
                if(flag == 0)
                {
                    res = s.substr(j) + s.substr(0,j);
                    flag++;
                }
                else
                {
                    temp = s.substr(j) + s.substr(0,j);
                    if(res > temp)//比较更新结果（字符串的比较就是按字典序比较的）
                    {
                        res = temp;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
