#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    string s,t;
    int ss[26],tt[26];
    while(cin>>s>>t)
    {
        int i,flag = 1;
        memset(ss,0,sizeof(ss));
        memset(tt,0,sizeof(tt));
        for(i = 0; i < s.length(); i++)//ͳ����ĸ���ִ���
        {
            ss[s[i] - 'A']++;
            tt[t[i] - 'A']++;
        }
        sort(ss,ss + 26);//��С��������
        sort(tt,tt + 26);
        for(i = 0; i < 26; i++)
            if(ss[i] != tt[i])
            {
                flag = 0;
                break;
            }
        if(flag == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
