#include <iostream>
#include <cstring>
using namespace std;

int father[200005];//�洢��ǰ��ĸ��ڵ�
int sum[200005];//�洢��ǰ�㵽���ڵ������֮��

int Find(int x)
{
    if(x != father[x])
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = sum[x] + sum[temp];
    }
    return father[x];
}

int main()
{
    int N,M,a,b,s,i;
    while(cin>>N>>M)
    {
        for(i = 0; i <= N ; i++)//�����ʼ��
        {
            father[i] = i;
            sum[i] = 0;
        }
        int ra,rb,num = 0;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>s;
            a--;//��Ϊ�ж�ʱ�ǿ�������ӣ�����Ҫ�������ұգ��������������һ
            ra = Find(a);
            rb = Find(b);
            if(ra == rb)//���������ڵ���ͬ
            {
                if(sum[a] != sum[b] + s)//�������������˵���Ǵ����
                    num++;
            }
            else
            {
                father[ra] = rb;//���ڵ���и���
                sum[ra] = s + sum[b] - sum[a];//������и���
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
