#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;//�ɸ���Ҫ�����ı��С

struct Edge//�߽ṹ��
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

//���·SPFA�㷨
bool SPFA(int start,int n)//start����ʼ�ڵ㣬n�ǽڵ�����
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
        for(j = head[u]; j >= 0; j = edge[j].next)//������u��ͨ�ĵ�
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
    int a,b,c;
    while(cin>>a>>b>>c)//�����ж���ߵĹ�ϵ
    {
        add(a,b,c);//������ʽǰ����
    }
    SPFA(start,n);//��ʼ�ڵ㣬�ڵ�����
    //cout<<length[m];�����Ҫ����̾���
    return 0;
}
