#include <iostream>
using namespace std;

#define M 1005

int father[M];//�洢��ǰ��ĸ��ڵ�
int sum[M];//�洢��ǰ�㵽���ڵ��Ȩֵ

int Find(int x)//��ѯx�ĸ��ڵ�,·��ѹ��,Ȩֵ����
{
    if(x != father[x])
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = sum[x] + sum[temp];
    }
    return father[x];
}

void Union()//�ϲ�
{
    //���������Լ���д
}

bool Query(int a,int b)//��ѯa��b�Ƿ���ͬһ����
{
    return Find(a) == Find(b);//���ڵ���ͬ��Ϊ��ͬһ����
}

int main()
{
    int i;
    for(i = 0; i < M; i++) //��ʼ��
    {
        sum[i] = 0;
        father[i] = i;
    }
    return 0;
}
