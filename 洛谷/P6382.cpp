#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        string s1 = s.substr(0,3);
        int i;
        for(i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] >= '0' && s[i] <= '9')
                break;
        }
        if(s1 == "MDA")
        {
            if(s[i] == '1' || s[i] == '9')
                printf("1 0 0 0 0\n");
            if(s[i] == '2' || s[i] == '8')
                printf("0 1 0 0 0\n");
            if(s[i] == '3' || s[i] == '7')
                printf("0 0 1 0 0\n");
            if(s[i] == '4' || s[i] == '6')
                printf("0 0 0 1 0\n");
            if(s[i] == '5' || s[i] == '0')
                printf("0 0 0 0 1\n");
        }
        else
        {
            printf("1 1 1 1 1\n");
        }
    }
    return 0;
}
