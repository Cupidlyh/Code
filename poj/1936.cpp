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

int main()
{
    char s[100005],t[100005];
    memset(s,0,sizeof(s));
    memset(t,0,sizeof(t));
    while (scanf("%s %s",s,t) != EOF)
    {

        int s_bit = 0;
        int s_len = strlen(s),t_len = strlen(t);

        for (int i = 0; i < t_len; i++)
        {
            if (s[s_bit] == t[i])
            {
                s_bit++;
            }
        }
        if (s_bit == s_len)
            printf("Yes\n");
        else
            printf("No\n");
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
    }
    return 0;
}
