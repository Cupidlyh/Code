#include <iostream>
#include <climits>

using namespace std;

long long int map[105][105];//��ͼ�Ĺ���
long long int length[105][105];//��¼��i��j�ľ���

void floyd(int n)//���������㷨
{
    int i,j,k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            length[i][j] = map[i][j];

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)//��i��K��j��һ��·������
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
        for(i = 0; i < 105; i++)//��ͼ�ĳ�ʼ��
            for(j = 0; j < 105; j++)
                map[i][j] = INT_MAX;
        int a,b,c;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>c;//�����ͼ
            map[a][b] = c;
            map[b][a] = c;

        }
        floyd(N);
        cout<<length[1][N]<<endl;
    }
    return 0;
}
