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
    int R,M,Y;
    double ans,temp;
    while (scanf("%d %d %d",&R,&M,&Y) != EOF)
    {
        ans = M;
        temp = 1 + R / 100.0;
        while (Y--)
        {
            ans *= temp;
        }
        printf("%d\n",(int)ans);
    }
    return 0;
}
