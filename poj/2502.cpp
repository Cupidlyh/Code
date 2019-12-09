#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include<cstdio>
using namespace std;

long double length[220][220];//��¼�㵽��֮��ķ�����
int x[220];//�����е�x����
int y[220];//�����е�y����
int ind = 1;//x��y������±�

long double len(int ax,int ay,int bx,int by)//�������֮���ֱ�߾���
{
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

void floyd(int n)//nΪͼ�Ķ���ĸ���
{
    int i,j,k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//��i��k��j��ʱ�����
                {
                    length[i][j] = length[i][k] + length[k][j];//����length[i][j]
                }
}

int main()
{
    int i,j,flag = 0;//flag����Ƿ�����ĵ���վ������һ��·
    double v1 = 10000.0 / 60;//���е��ٶȣ�m/min��
    double v2 = 40000.0 / 60;//�������ٶȣ�m/min��
    for(i = 0; i < 220; i++)//��ʼ��
        for(j = 0; j < 220; j++)
            if(i == j)
                length[i][j] = 0;
            else
                length[i][j] = INT_MAX;
    cin>>x[ind]>>y[ind];//�������
    ind++;
    cin>>x[ind]>>y[ind];//�����յ�
    ind++;
    while(cin>>x[ind]>>y[ind])//��������վ������
    {
        if(x[ind] == -1 && y[ind] == -1)//��������һ��·
        {
            flag = 1;//���
            continue;
        }
        if(flag == 1)//ǰһ��·���յ㵽����·�������Ҫ����
        {
            length[ind - 1][ind] = len(x[ind - 1],y[ind - 1],x[ind],y[ind]) / v1;//����ʱ��
            length[ind][ind - 1] = length[ind - 1][ind];//����ͼ
            flag = 0;//ȡ�����
            ind++;
            continue;
        }
        if(ind == 3)//��㵽��һ����·�ĵ�һ��վ��ҲҪ����
        {
            length[1][3] = len(x[1],y[1],x[3],y[3]) / v1;//����ʱ��
            length[3][1] = length[1][3];
        }
        if(ind > 3)
        {
            length[ind - 1][ind] = len(x[ind - 1],y[ind - 1],x[ind],y[ind]) / v2;//�����������վ��֮�����е�ʱ�䣨��������
            length[ind][ind - 1] = length[ind - 1][ind];
        }
        ind++;
    }
    length[ind - 1][2] = len(x[ind - 1],y[ind - 1],x[2],y[2]) / v1;//����ʱ�䣨���һ����·���յ���Ҫ���У�
    length[2][ind - 1] = length[ind - 1][2];
    for(i = 1; i < ind; i++)
        for(j = 1; j < ind; j++)
            if(length[i][j] == INT_MAX)//����δ��ͨ�ĵ㶼����ͨ�����е���
            {
                length[i][j] = len(x[i],y[i],x[j],y[j]) / v1;//����ʱ��
                length[j][i] = length[i][j];//����ͼ
            }
    floyd(ind - 1);//���������㷨
    cout<<(int)(length[1][2] + 0.5)<<endl;//���Ҫ��������
    return 0;
}
