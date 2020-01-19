#include <iostream>
using namespace std;

int father[30005];//��¼���ڵ�

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
int main()//���첢�鼯��֪ʶ
{
    int n,m,i,j,k,d,p;
    while(cin>>n>>m)
    {
        if(n == 0 && m == 0)
            break;
        if(m == 0)
            cout<<1<<endl;
        else
        {
            for(i = 0; i < n; i++)//�����ʼ��
                father[i] = i;
            for(i = 0; i < m; i++)
            {
                cin>>k>>d;
                for(j = 0; j < k - 1; j++)
                {
                    cin>>p;
                    Union(d,p);
                }
            }
            int num = 0;
            for(i = 1; i < n; i++)
                if(Find(i) == Find(0))//��ѯ�Ƿ���ͬһ��������
                    num++;
            cout<<++num<<endl;
        }
    }
    return 0;
}
