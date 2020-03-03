#include <iostream>
using namespace std;

int father[10000005];//��¼���ڵ�
int num[10000005];//���ڼ�¼�м������Ϻ�ÿ��������Ԫ�ص�����

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

int main()
{
    int n,a,b,i;
    while(cin>>n)
    {
        if(n == 0)
        {
            cout<<1<<endl;
            continue;
        }
        for(i = 0; i < 10000005; i++)//��ʼ��
        {
            father[i] = i;
            num[i] = 0;
        }
        int maxx = 0;//�ҳ����ѵ������
        for(i = 0; i < n; i++)
        {
            cin>>a>>b;
            Union(a,b);
            if(a > b)
                maxx = maxx > a ? maxx : a;
            else
                maxx = maxx > b ? maxx : b;
        }
        for(i = 1; i <= maxx; i++)//���ڵ���ͬ����Ϊ��ͬһ������֮��
            num[Find(i)]++;
        int res = 0;
        for(i = 1; i <= maxx; i++)
            if(num[i] > res)//�ҳ����м�����Ԫ�������Ǹ�
                res = num[i];
        cout<<res<<endl;
    }
    return 0;
}
