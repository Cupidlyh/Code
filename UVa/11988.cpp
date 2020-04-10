#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        list<char>ans;//链表
        list<char>::iterator it = ans.begin();//迭代器
        int i;
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == '[')//Home键功能
                it = ans.begin();
            else if(s[i] == ']')//End键功能
                it = ans.end();
            else
            {
                it = ans.insert(it,s[i]);
                it++;
            }
        }
        for(it = ans.begin(); it != ans.end(); it++)
            cout<<*it;
        cout<<endl;
    }
    return 0;
}
