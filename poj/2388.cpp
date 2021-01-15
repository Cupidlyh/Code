#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10005];
    int N;
    while (scanf("%d",&N) != EOF)
    {
        memset(arr,0,sizeof(arr));
        for (int i = 0; i < N; i++)
            scanf("%d",&arr[i]);
        sort(arr,arr + N);
        printf("%d\n",arr[N / 2]);
    }
    return 0;
}
