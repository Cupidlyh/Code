#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    string s,s1;
    int arr_s[26] = {0},arr_s1[26] = {0};
    while(cin>>s>>s1)
    {
        int i;
        for(i = 0; i < s.length(); i++)
        {
            arr_s[s[i] - 'A']++;
            arr_s1[s1[i] - 'A']++;
        }
        sort(arr_s,arr_s + 26);
        sort(arr_s1,arr_s1 + 26);
        for(i = 0; i < 26; i++)
        {
            if(arr_s[i] != arr_s1[i])
                break;
        }
        if(i != 26)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
