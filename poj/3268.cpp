#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int map[1005][1005];//�����������ͼ
int map1[1005][1005];//�����������ͼ������ĵ������洢��
int qusign[1005];//�������
int huisign[1005];
int qu_len[1005];//��¼ĸţȥ�Ĺ����д���㵽��ǰλ�õľ���
int hui_len[1005];//��¼ĸţ�����Ĺ����д���㵽��ǰλ�õľ���


void qu_dij(int x,int n)
{
    memset(qusign,0,sizeof(qusign));
    int i,v,w,min;
    for(v = 1; v <= n; v++)
    {
        qu_len[v] = INT_MAX;
        if(map1[x][v] != -1)
            qu_len[v] = map1[x][v];
    }
    qu_len[x] = 0;
    qusign[x] = 1;

    for(i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(qusign[w] == 0 && qu_len[w] < min)
            {
                v = w;
                min = qu_len[w];
            }
        }
        qusign[v] = 1;
        for(w = 1; w <= n; w++)
        {
            if(map1[v][w] != -1 && qusign[w] == 0 && (qu_len[v] + map1[v][w] < qu_len[w]))
            {
                qu_len[w] = qu_len[v] + map1[v][w];
            }
        }
    }
}

void hui_dij(int x,int n)
{
    memset(huisign,0,sizeof(huisign));//��������ʼ��
    int i,v,w,min;
    for(v = 1; v <= n; v++)//n���������γ�ʼ��
    {
        hui_len[v] = INT_MAX;
        if(map[x][v] != -1)
            hui_len[v] = map[x][v];//��x�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
    }
    hui_len[x] = 0;//Դ�㵽Դ��ľ���Ϊ0
    huisign[x] = 1;//��Դ����뵽���������

    //��ʼ����������ʼѭ����ÿ�����x��ĳ������v�����·������v���뵽���������
    for(i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(huisign[w] == 0 && hui_len[w] < min)//ѡ��һ����ǰ�����·�����յ�Ϊv
            {
                v = w;
                min = hui_len[w];
            }
        }
        huisign[v] = 1;//��v������������
        for(w = 1; w <= n; w++)//���´�x����������v-s�����ж�������·������
        {
            if(map[v][w] != -1 && huisign[w] == 0 && (hui_len[v] + map[v][w] < hui_len[w]))
            {
                hui_len[w] = hui_len[v] + map[v][w];//����hui_len[w]
            }
        }
    }
}

int main()
{
    int N,M,X;
    while(cin>>N>>M>>X)
    {
        memset(map,-1,sizeof(map));//����ͼ�ĳ�ʼ��
        memset(map1,-1,sizeof(map1));
        int i,a,b,c;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>c;
            map[a][b] = c;//�洢��ʼ������ͼ
            map1[b][a] = c;//������ͼ�������洢
        }
        hui_dij(X,N);//ĸţ�������ߵ�·��
        qu_dij(X,N);//ĸţ��ȥ���ߵ�·��
        int max = INT_MIN;
        for(i = 1; i <= N; i++)
        {
            if(i == X)
                continue;
            if(qu_len[i] + hui_len[i] > max)//��������ĸţ�е����·��
                max = qu_len[i] + hui_len[i];
        }
        cout<<max<<endl;
    }
    return 0;
}
