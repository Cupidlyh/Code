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
    int N,x,y;
    while (scanf("%d",&N) != EOF)
    {
        while (N--)
        {
            scanf("%d %d",&x,&y);
            if (x < y)
                printf("NO BRAINS\n");
            else
                printf("MMM BRAINS\n");
        }
    }
    return 0;
}
