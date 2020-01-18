#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int map[105][105];

//֮�������鿪�ٳ�long long int����Ϊ��ֹ�����п��ܳ���Խ������
int sign[105];//��¼��Դ��v0���յ��Ƿ��Ѿ���ȷ�����·��
long long int length[105];//��¼��Դ��v0���յ�ĵ�ǰ���·������

//�õϽ�˹�����㷨������ͼ��v0�㵽�����������·��
void dijkstra(int Graph[105][105],int v0,int n)//nΪ����ͼ�������
{
    memset(sign,0,sizeof(sign));//sign��ʼ��Ϊ0
    int i,v,w,min;
    for(v = 1; v <= n; v++)//n���������γ�ʼ��
    {
        length[v] = Graph[v0][v];//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
    }
    length[v0] = 0;//Դ�㵽Դ��ľ���Ϊ0
    sign[v0] = 1;//��v0���뵽sign��

    //��ʼ����������ʼѭ����ÿ�����v0��ĳ������v�����·������v���뵽sign��
    for(i = 2; i <= n; i++)//������n-1���������ν��м���
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(sign[w] == 0 && length[w] < min)//ѡ��һ����ǰ�����·�����յ�Ϊv
            {
                v = w;
                min = length[w];
            }
        }
        sign[v] = 1;//��v����sign��
        for(w = 1; w <= n; w++)//���´�v0����������v-s�����ж�������·������
        {
            if(sign[w] == 0 && (length[v] + Graph[v][w] < length[w]))
            {
                length[w] = length[v] + Graph[v][w];//����length[w]
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        int i,j;
        char s[10];
        int max = INT_MIN;
        for(i = 1; i <= n; i++)//��ͼ��ʼ��
            for(j = 1; j <= n; j++)
                if(i != j)
                    map[i][j] = INT_MAX;
                else
                    map[i][j] = 0;

        for(i = 2; i <= n; i++)
            for(j = 1; j < i; j++)
            {
                cin>>s;
                if(s[0] != 'x')
                    map[i][j] = map[j][i] = atoi(s);//���ַ���ת��Ϊ����
            }

        dijkstra(map,1,n);//nΪ����ͼ��������1ΪԴ��
        for(i = 1; i <= n; i++)
            if(length[i] > max)//�����е����·�����ҳ�һ������
                max = length[i];
        cout<<max<<endl;
    }
    return 0;
}
