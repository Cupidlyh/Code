#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 0x3f3f3f3f//��ֹ����������������̫��
#define N 1000//����Ĵ�С����������Ĺ�ģ���ı�

int sign[N];//��¼��Դ��v0���յ��Ƿ��Ѿ���ȷ�����·��
int path[N];//��¼��Դ��v0���յ�ĵ�ǰ·���ϵ�ֱ��ǰ���������
int length[N];//��¼��Դ��v0���յ�ĵ�ǰ���·������


//�õϽ�˹�����㷨������ͼ��v0�㵽�����������·��
void dijkstra(int Graph[N][N],int v0,int n)//nΪ����ͼ�������
{
    memset(sign,0,sizeof(sign));//sign��ʼ��Ϊ0
    int i,v,w,min;
    for(v = 0; v < n; v++)//n���������γ�ʼ��
    {
        length[v] = Graph[v0][v];//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
        if(length[v] < INF)//���v0��v֮���л�����v��ǰ����Ϊv0
            path[v] = v0;
    }
    length[v0] = 0;//Դ�㵽Դ��ľ���Ϊ0
    sign[v0] = 1;//��v0���뵽sign��

    //��ʼ����������ʼѭ����ÿ�����v0��ĳ������v�����·������v���뵽sign��
    for(i = 1; i < n; i++)//������n-1���������ν��м���
    {
        min = INF;
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
    int Graph[N][N];//����ͼGraph
    for(int i = 0; i < N; i++)//��ʼ��GraphΪINF�����Ա�ʾ������
        for(int j = 0; j < N; j++)
            Graph[i][j] = INF;
    //scanf("%d",&Graph[m][n]); �����ж�������ͼ
    dijkstra(Graph,0,n);//nΪ����ͼ��������0ΪԴ�㣨������������Դ��,�������ı����[0,n)��
    //printf();�������Ҫ�����·��
    return 0;
}
