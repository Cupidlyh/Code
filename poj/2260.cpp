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
    int N;
    int arr[105][105];
    int col[105],row[105];
    while (scanf("%d",&N) != EOF)
    {
        if (N == 0)
            break;
        memset(arr,0,sizeof(arr));
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d",&arr[i][j]);
                row[i] += arr[i][j];
                col[j] += arr[i][j];
            }
        }
        int r = 0,c = 0;
        int x,y;
        for (int i = 1; i <= N; i++)
        {
            if (row[i] % 2 != 0)
            {
                c++;
                if (c >= 2)
                    break;
                x = i;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (col[i] % 2 != 0)
            {
                r++;
                if (r >= 2)
                    break;
                y = i;
            }
        }
        if (c == 0 && r == 0)
            printf("OK\n");
        if (c == 1 && r == 1)
            printf("Change bit (%d,%d)\n",x,y);
        if (c == 2 || r == 2)
            printf("Corrupt\n");
    }
    return 0;
}
