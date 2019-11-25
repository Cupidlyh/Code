#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int sign[205];//��ǵ��Ƿ��߹�
double length[205];//��¼Դ�㵽��ǰ������·���е������е���С��
double Graph[205][2];//���ͼ
int n;

double max(double a,double b)//�Ƚϴ�С
{
    if(a > b)
        return a;
    return b;
}

double distance(double a,double b,double c,double d)//���������ľ���
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}


void dijkstra()
{
    int i,v,w,min;
    for(v = 0; v < n; v++)//��ʼ��
    {
        sign[v] = 0;
        length[v] = INT_MAX;
    }
    length[0] = 0;//Դ�㵽Դ������Ϊ0

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
        for(w = 0; w < n; w++)
        {
            if(sign[w] == 0 && max(length[v],distance(Graph[v][0],Graph[v][1],Graph[w][0],Graph[w][1])) < length[w])//��Ϊ����������·���������е���С�ߣ��������������
            {
                length[w]=max(length[v],distance(Graph[v][0],Graph[v][1],Graph[w][0],Graph[w][1]));

            }
        }
    }
}

int main()
{
    int m = 0;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        m++;
        int i = 0;
        for(i = 0; i < n; i++)
            scanf("%lf %lf",&Graph[i][0],&Graph[i][1]);
        dijkstra();
        printf("Scenario #%d\n",m);
        printf("Frog Distance = %.3lf\n\n",length[1]);
        getchar();
    }
    return 0;
}
