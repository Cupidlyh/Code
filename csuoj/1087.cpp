#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int h1,m1,h2,m2;
    int day = 1;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2) != EOF)
    {
        if(h2 < h1 || (h1 == h2 && m1 > m2))
        {
            printf("Day %d: Joking\n",day++);
            continue;
        }
        int w,v,minutes;
        if(h1 == h2)
        {
            w = (m2 - m1) / 30 + 1;
            v = 30 - ((m2 - m1) % 30);
        }
        else
        {
            minutes = 60 - m1 + (h2 - 1 - h1) * 60 + m2;
            w = minutes / 30 + 1;
            v = 30 - (minutes % 30);
        }
        printf("Day %d: %d %d\n",day++,w,v);
    }
    return 0;
}
