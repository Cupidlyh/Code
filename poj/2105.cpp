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

char s[35];
int bitt[8] = {1,2,4,8,16,32,64,128};

int cal(int sta, int end)
{
    int sum = 0;
    int bit = 0;
    for (int i = end - 1; i >= sta; i--)
    {
        sum += (s[i] - '0') * bitt[bit++];
    }
    return sum;
}

int main()
{
    int N;
    while (scanf("%d",&N) != EOF)
    {

        while (N--)
        {
            memset(s,0,sizeof(s));
            scanf("%s",s);
            int IP1,IP2,IP3,IP4;
            IP1 = cal(0,8);
            IP2 = cal(8,16);
            IP3 = cal(16,24);
            IP4 = cal(24,32);
            printf("%d.%d.%d.%d\n",IP1,IP2,IP3,IP4);
        }
    }
    return 0;
}

