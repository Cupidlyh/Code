#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 7000;//�ɸ���Ҫ�����ı��С

struct Edge//�߽ṹ��
{
    int next;//���i����ͬһ������һ���ߵ�λ��
    int to;//�˱ߵ��յ�
    int len;//�ߵ�Ȩֵ
} edge[MAXN];
int head[MAXN];//��iΪ���ĵ�һ���ߴ洢��λ�ã�ʵ�������������Ǹ���ţ�
int index = 0;


bool vis[MAXN];//������ǵ��Ƿ��ڶ�����
int num[MAXN];//ÿ���������д���
int length[MAXN];//��¼����㵽��n��·����



void add(int start,int end,int len)//��ʽǰ���ǵļӱߺ���
{
    edge[index].len = len;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}

bool SPFA(int start,int n)//start����ʼ�ڵ㣬n�ǽڵ�����
{
    int i,j;
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    for(i = 0; i <MAXN; i++)
    {
        length[i] = INT_MAX;
    }
    queue<int>que;
    while(!que.empty())
        que.pop();
    que.push(start);//���
    vis[start] = true;//��Ǵ˵������
    length[start] = 0;//Դ�㵽Դ��ĳ���Ϊ0
    num[start]++;//��Ӵ�����1
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
                    num[v]++;//��Ӵ�����1
                    if(num[v] > n)//����������볬��n�Σ�˵�����ڸ�Ȩ��·��ֱ�ӷ���
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int F,N,M,W,S,E,T;
    while(cin>>F)
    {
        int i;
        while(F--)
        {
            memset(head,-1,sizeof(head));
            index = 0;
            cin>>N>>M>>W;
            for(i = 1; i <= M; i++)
            {
                cin>>S>>E>>T;
                add(S,E,T);
                add(E,S,T);
            }
            for(; i <= M + W; i++)
            {
                cin>>S>>E>>T;
                add(S,E,-T);
            }
            if(SPFA(1,N))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
