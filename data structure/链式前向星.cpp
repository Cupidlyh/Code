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


void add(int start,int end,int len)//��ʽǰ���ǵļӱߺ���
{
    edge[index].len = len;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)//�����ж���ߵĹ�ϵ
    {
        add(a,b,c);//������ʽǰ����
    }
    return 0;
}
