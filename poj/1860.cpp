#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1100;

struct Edge//�߽ṹ��
{
    int next;//���i����ͬһ������һ���ߵ�λ��
    int to;//�˱ߵ��յ�
    double yongjin;//Ӷ��
    double huilv;//����
} edge[MAXN];
int head[MAXN];//��iΪ���ĵ�һ���ߴ洢��λ�ã�ʵ�������������Ǹ���ţ�
int index = 0;


bool vis[MAXN];//������ǵ��Ƿ��ڶ�����
int num[MAXN];//ÿ���������д���
double length[MAXN];//��¼����㵽��n��Ǯ��

void add(int start,int end,double huilv,double yongjin)//��ʽǰ���ǵļӱߺ���
{
    edge[index].huilv = huilv;
    edge[index].yongjin = yongjin;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}


bool SPFA(int start,int n,double temp)//start����ʼ�ڵ㣬n�ǽڵ�������temp�ǳ�ʼǮ��
{
    int j;
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    memset(length,0,sizeof(length));
    length[start] = temp;
    queue<int>que;
    while(!que.empty())
        que.pop();
    que.push(start);//���
    vis[start] = true;//��Ǵ˵������
    num[start]++;//��Ӵ�����1
    while(!que.empty())
    {
        int u = que.front();
        que.pop();//����
        vis[u] = false;//��Ǵ˵��Ѿ����ڶ�����
        for(j = head[u]; j >= 0; j = edge[j].next)//������u��ͨ�ĵ�
        {
            int v = edge[j].to;
            if(length[v] < (length[u] - edge[j].yongjin) * edge[j].huilv)
            {
                length[v] = (length[u] - edge[j].yongjin) * edge[j].huilv;//Ǯ������
                if(vis[v] == 0)//���v�㲻�ڶ�����
                {
                    que.push(v);//���
                    vis[v] = 1;//���
                    num[v]++;//��Ӵ�����1
                    if(num[v] > n)//����������볬��n�Σ�˵������������·��ֱ�ӷ���
                        return true;
                }
            }
            if(length[start] > temp)//���Ǯ�����ڳ�ʼֵ��ͬһ��Ǯ��
                return true;
        }
    }
    return false;
}


int main()
{
    int n,m,s;
    double v;
    while(cin>>n>>m>>s>>v)
    {
        memset(head,-1,sizeof(head));
        int i,a,b;
        double c,d,e,f;
        for(i = 0; i < m; i++)
        {
            cin>>a>>b>>c>>d>>e>>f;
            add(a,b,c,d);//����ǰ����
            add(b,a,e,f);
        }
        if(SPFA(s,n,v))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
