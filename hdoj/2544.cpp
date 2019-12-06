#include <iostream>
#include <climits>

using namespace std;

long long int map[105][105];//地图的构建
long long int length[105][105];//记录从i到j的距离

void floyd(int n)//弗洛伊德算法
{
    int i,j,k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            length[i][j] = map[i][j];

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)//从i经K到j的一条路径更短
                if(length[i][k] + length[k][j] < length[i][j])
                    length[i][j] = length[i][k] + length[k][j];
}

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        if(N == 0 && M == 0)
            break;
        int i,j;
        for(i = 0; i < 105; i++)//地图的初始化
            for(j = 0; j < 105; j++)
                map[i][j] = INT_MAX;
        int a,b,c;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>c;//读入地图
            map[a][b] = c;
            map[b][a] = c;

        }
        floyd(N);
        cout<<length[1][N]<<endl;
    }
    return 0;
}
