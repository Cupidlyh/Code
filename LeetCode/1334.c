#include <stdio.h>
#include <stdlib.h>

long long int length[105][105];//记录顶点i和j之间的最短路径长度

void floyd(int Graph[105][105],int n)//n为图的顶点的个数
{
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            length[i][j] = Graph[i][j];//各对节点初始已知距离
        }
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//从i经k到j的一条路径更短
                {
                    length[i][j] = length[i][k] + length[k][j];//更新length[i][j]
                }
}

int find_min(int arr[105],int n)//在一维数组中找出一个最小值
{
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
{
    int length1[105][105],i,j,num[105] = {0};
    memset(length,0,sizeof(length));
    for(int i = 0; i < n; i++)//初始化length1为整型最大值，用以表示无连接
        for(int j = 0; j < n; j++)
            length1[i][j] = INT_MAX;
    for(i = 0; i < edgesSize; i++)  //将城市之间的关系存进图里
    {
        length1[edges[i][0]][edges[i][1]] = length1[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    floyd(length1,n);//算出每个城市之间的最短距离
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            if(length[i][j] <= distanceThreshold)//统计每个城市到其他城市的距离小于阈值的个数
                num[i]++;
        }
    }
    int min = find_min(num,n);
    for(i = n - 1; i >= 0; i--)  //因为返回最大的编号所以倒着遍历
    {
        if(num[i] == min)
            break;
    }
    return i;
}
