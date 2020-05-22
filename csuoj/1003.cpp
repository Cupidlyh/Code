#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        string s;
        scanf("%d",&n);
        cin>>s;
        int experience = 0,day = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                day++;
                experience += (day % 5) * 10;
            }
            else
            {
                day = 0;
            }
            if(experience >= 750)
                break;
        }
        if(experience <= 49)
            printf("0\n");
        if(experience >= 50 && experience <= 149)
            printf("1\n");
        if(experience >= 150 && experience <= 249)
            printf("2\n");
        if(experience >= 250 && experience <= 349)
            printf("3\n");
        if(experience >= 350 && experience <= 449)
            printf("4\n");
        if(experience >= 450 && experience <= 549)
            printf("5\n");
        if(experience >= 550 && experience <= 649)
            printf("6\n");
        if(experience >= 650 && experience <= 749)
            printf("7\n");
        if(experience >= 750)
            printf("8\n");
    }
    return 0;
}
