#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;//��ֹ����������������̫��
const int MAXN=1000010;//����Ĵ�С����������Ĺ�ģ���ı�

struct qnode//����cֵ�Ĵ�С��cֵС���ȳ�����
{
    //��v��c��Ӧ�ľ���Edge�е�v��cost
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};

struct Edge
{
    int v;//�յ�
    int cost;//��㵽�յ�v�ľ���
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector<Edge>E[MAXN];//�洢ͼ����Ϣ
bool vis[MAXN];//��¼��Դ��v0���յ��Ƿ��Ѿ���ȷ�����·��
int dist[MAXN];//��¼��Դ��v0���յ�ĵ�ǰ���·������

void Dijkstra(int n,int start)//��ı�Ŵ�0��ʼ
{
    memset(vis,false,sizeof(vis));//vis��ʼ��Ϊfalse
    for(int i=0; i<n; i++)//n���������γ�ʼ��
        dist[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty())
        que.pop();
    dist[start]=0;//Դ�㵽Դ��ľ���Ϊ0
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        //���ȶ��е����ʣ��������ľ������·��
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])
            continue;
        vis[u]=true;
        //���´�v0����������v-s�����ж�������·������
        for(int i=0; i<E[u].size(); i++)
        {
            int v=E[u][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;//���ȸ���
                que.push(qnode(v,dist[v]));
            }
        }
    }
}

//�ӱߺ�������ͼ��
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}

int main()
{
    Dijkstra(n,start);//n�ǵ�ĸ�����start�����
    return 0;
}
