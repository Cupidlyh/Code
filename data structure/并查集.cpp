#include <iostream>
using namespace std;

#define M 1005

int father[M];//��¼���ڵ�

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
    int i;
    for(i = 0; i < M; i++)//��ʼ��
        father[i] = i;

    return 0;
}
