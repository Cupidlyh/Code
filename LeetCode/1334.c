#include <stdio.h>
#include <stdlib.h>

long long int length[105][105];//��¼����i��j֮������·������

void floyd(int Graph[105][105],int n)//nΪͼ�Ķ���ĸ���
{
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            length[i][j] = Graph[i][j];//���Խڵ��ʼ��֪����
        }
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//��i��k��j��һ��·������
                {
                    length[i][j] = length[i][k] + length[k][j];//����length[i][j]
                }
}

int find_min(int arr[105],int n)//��һά�������ҳ�һ����Сֵ
{
    int min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
{
    int length1[105][105],i,j,num[105] = {0};
    memset(length,0,sizeof(length));
    for(int i = 0; i < n; i++)//��ʼ��length1Ϊ�������ֵ�����Ա�ʾ������
        for(int j = 0; j < n; j++)
            length1[i][j] = INT_MAX;
    for(i = 0; i < edgesSize; i++)  //������֮��Ĺ�ϵ���ͼ��
    {
        length1[edges[i][0]][edges[i][1]] = length1[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    floyd(length1,n);//���ÿ������֮�����̾���
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            if(length[i][j] <= distanceThreshold)//ͳ��ÿ�����е��������еľ���С����ֵ�ĸ���
                num[i]++;
        }
    }
    int min = find_min(num,n);
    for(i = n - 1; i >= 0; i--)  //��Ϊ�������ı�����Ե��ű���
    {
        if(num[i] == min)
            break;
    }
    return i;
}
