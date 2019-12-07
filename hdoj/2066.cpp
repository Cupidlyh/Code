#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;

struct Edge//��ʽǰ����
{
    int next;//���i����ͬһ������һ���ߵ�λ��
    int to;//�˱ߵ��յ�
    int len;//�ߵ�Ȩֵ
} edge[MAXN];
int head[MAXN];//��iΪ���ĵ�һ���ߴ洢��λ�ã�ʵ�������������Ǹ���ţ�
int index = 0;


bool vis[MAXN];//������ǵ��Ƿ��ڶ�����
int cnt[MAXN];//ÿ���������д���
int length[MAXN];//��¼����㵽��n��·����


void add(int start,int end,int len)//��ʽǰ���ǵļӱߺ���
{
    edge[index].len = len;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}


bool SPFA(int start,int n)//���·SPFA�㷨
{
    int i,j;
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(i = 0; i <MAXN; i++)
    {
        length[i] = INT_MAX;
    }
    queue<int>que;
    que.push(start);//���
    vis[start] = true;//��Ǵ˵������
    length[start] = 0;//Դ�㵽Դ��ĳ���Ϊ0
    cnt[start]++;//��Ӵ�����1
    while(!que.empty())
    {
        int u = que.front();
        que.pop();//����
        vis[u] = false;//��Ǵ˵��Ѿ����ڶ�����
        for(j = head[u]; j != -1; j = edge[j].next)//������u��ͨ�ĵ�
        {
            int v = edge[j].to;
            if(length[v] > length[u] + edge[j].len)
            {
                length[v] = length[u] + edge[j].len;//·������
                if(vis[v] == 0)//���v�㲻�ڶ�����
                {
                    que.push(v);//���
                    vis[v] = 1;//���
                    cnt[v]++;//��Ӵ�����1
                    if(cnt[v] > n)//����������볬��n�Σ�˵�����ڸ�����·��ֱ�ӷ���
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int T,S,D;
    while(cin>>T>>S>>D)
    {
        int i,j,a,b,time,start[MAXN],end[MAXN],minn = INT_MAX;
        memset(head,-1,sizeof(head));
        for(i = 0; i < T; i++)
        {
            cin>>a>>b>>time;
            add(a,b,time);//������ʽǰ����
            add(b,a,time);
        }
        for(i = 0; i < S; i++)
            cin>>start[i];//�������ڳ���
        for(i = 0; i < D; i++)
            cin>>end[i];//����Ŀ�����
        for(i = 0; i < S; i++)
        {
            SPFA(start[i],T);//SPFA�㷨
            for(j = 0; j < D; j++)
                minn = min(minn,length[end[j]]);//�ҵ�Ŀ����л��ѵ����ʱ��
        }
        cout<<minn<<endl;
    }
    return 0;
}
