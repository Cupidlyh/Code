#include <iostream>
#include <climits>
using namespace std;

#define N 1000//����Ĵ�С����������Ĺ�ģ���ı�

//֮�������鿪�ٳ�long long int����Ϊ��ֹ�����п��ܳ���Խ������
int path[N][N];//���·���϶���j��ǰһ��������
long long int length[N][N];//��¼����i��j֮������·������


//�ø��������㷨��������Graph�и��Զ���i��j֮������·��
void floyd(int Graph[N][N],int n)//nΪͼ�Ķ���ĸ���
{
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            length[i][j] = Graph[i][j];//���Խڵ��ʼ��֪����
            if(length[i][j] < INT_MAX && i != j)
                path[i][j] = i;//���i��j֮���л���j��ǰ����Ϊi
            else
                path[i][j] = -1;//���i��j֮���޻���j��ǰ����Ϊ-1
        }

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//��i��k��j��һ��·������
                {
                    length[i][j] = length[i][k] + length[k][j];//����length[i][j]
                    path[i][j] = path[k][j];//����j��ǰ��Ϊk
                }
}

int main()
{
    int Graph[N][N];//����ͼGraph
    for(int i = 0; i < N; i++)//��ʼ��GraphΪ�������ֵ�����Ա�ʾ������
        for(int j = 0; j < N; j++)
            Graph[i][j] = INT_MAX;
    //cin>>Graph[m][n];������������ͼ
    floyd(Graph,n)//nΪͼ�Ķ���ĸ���
    //cout<<length[m][n];�����������Ҫ�����·��
    return 0;
}
