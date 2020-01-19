#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct mp
{
    int x,y;
} node[1005];//�洢�����������

int vis[1005];//���޺õĵ�Ž���������
int father[1005];//��¼���ڵ�

int Find(int x)//��ѯx�ĸ��ڵ㲢·��ѹ��
{
    if(father[x] != x)
        father[x] = Find(father[x]);
    return father[x];
}

void Union(int x,int y)//�ϲ�x��y�ļ���
{
    int rx,ry;
    rx=Find(x);
    ry=Find(y);
    if(rx!=ry)
        father[rx]=ry;
}

double length(int x,int y)
{
    return sqrt((node[x].x - node[y].x) * (node[x].x - node[y].x) + (node[x].y - node[y].y) * (node[x].y - node[y].y));
}


int main()//���⿼�鲢�鼯��֪ʶ
{
    int N,d,i,m,n,bit = 0;
    cin>>N>>d;
    memset(vis,0,sizeof(vis));
    for(i = 1; i <= N; i++)
    {
        cin>>node[i].x>>node[i].y;
        father[i] = i;//���鼯�м�¼���ڵ�������ʼ��
    }
    char c;
    while(cin>>c)
    {
        if(c == 'O')
        {
            cin>>m;
            vis[bit++] = m;
            if(bit >= 2)
            {
                for(i = 0; i < bit - 1; i++)
                {
                    if(length(vis[i],m) <= d)//���������֮��ľ���С��d
                        Union(vis[i],m);//��������

                }
            }
        }
        if(c == 'S')
        {
            cin>>m>>n;
            if(Find(m) == Find(n))//�������ĸ�����ͬһ����
                cout<<"SUCCESS"<<endl;//���ǳɹ�
            else
                cout<<"FAIL"<<endl;
        }
    }
    return 0;
}
