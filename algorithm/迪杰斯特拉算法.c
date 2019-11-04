#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 1000//����Ĵ�С����������Ĺ�ģ���ı�

//֮�������鿪�ٳ�long long int����Ϊ��ֹ�����п��ܳ���Խ������
long long int sign[N];//��¼��Դ��v0���յ��Ƿ��Ѿ���ȷ�����·��
long long int path[N];//��¼��Դ��v0���յ�ĵ�ǰ·���ϵ�ֱ��ǰ���������
long long int length[N];//��¼��Դ��v0���յ�ĵ�ǰ���·������


//�õϽ�˹�����㷨������ͼ��v0�㵽�����������·��
void dijkstra(int Graph[N][N],int v0,int n)//nΪ����ͼ�������
{
    int i,v,w,min;
    for(v = 0; v < n; v++)//n���������γ�ʼ��
    {
        length[v] = Graph[v0][v];//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
        if(length[v] < INT_MAX)//���v0��v֮���л�����v��ǰ����Ϊv0
            path[v] = v0;
    }
    path[v0] = 0;//Դ�㵽Դ��ľ���Ϊ0
    sign[v0] = 1;//��v0���뵽sign��

    //��ʼ����������ʼѭ����ÿ�����v0��ĳ������v�����·������v���뵽sign��
    for(i = 1; i < n; i++)
    {
        min = INT_MAX;
        for(w = 0; w < n; w++)
        {
            if(sign[w] == 0 && length[w] < min)//ѡ��һ����ǰ�����·�����յ�Ϊv
            {
                v = w;
                min = length[w];
            }
        }
        sign[v] = 1;//��v����sign��
        for(w = 0; w < n; w++)//���´�v0����������v-s�����ж�������·������
        {
            if(sign[w] == 0 && (length[v] + Graph[v][w] < length[w]))
            {
                length[w] = length[v] + Graph[v][w];//����length[w]
                path[w] = v;//����w��ǰ��Ϊv
            }
        }
    }
}


int main()
{
    memset(sign,0,sizeof(sign));//sign��ʼ��Ϊ0
    memset(path,-1,sizeof(path));//path��ʼ��Ϊ-1
    for(int j = 0; j < N; j++)//��ʼ��lengthΪ�������ֵ
        length[j] = INT_MAX;
    int Graph[N][N];//����ͼGraph
    for(int i = 0; i < N; i++)//��ʼ��GraphΪ�������ֵ�����Ա�ʾ������
        for(int j = 0; j < N; j++)
            Graph[i][j] = INT_MAX;
    //scanf("%d",&Graph[m][n]); �����ж�������ͼ
    dijkstra(Graph,1,N);//NΪ����ͼ��������1ΪԴ�㣨������������Դ�㣩
    //printf();�������Ҫ�����·��
    return 0;
}
