#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct qnode
{
    int c;
    qnode(int _c=0):c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;//�ȷ������С��
    }
};

int main()
{
    int N,M;
    while(scanf("%d %d",&N,&M) != EOF)
    {
        int p1,p2;
        // �洢����ͼ
        vector<vector<int> > edges;
        // �洢ÿ���ڵ�����
        vector<int> indeg;
        // �洢��
        vector<int> result;
        edges.resize(N + 1);
        indeg.resize(N + 1);
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d",&p1,&p2);
            edges[p1].push_back(p2);
            indeg[p2]++;
        }
        //���ȶ��д洢���Ϊ0�ĵ㣨��Ϊ��ȷ������˳��
        priority_queue<qnode> q;
        for(int i = 1; i < indeg.size(); i++)
        {
            if(indeg[i] == 0)//���Ϊ0�ĵ��ȴ��������
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.top().c;
            q.pop();
            result.push_back(u);
            for(int i = 0; i < edges[u].size(); i++)  //u��Ϊȥ�����ĵ㣬����Ҫ����u��������ȼ�1
            {
                indeg[edges[u][i]]--;
                if(indeg[edges[u][i]] == 0)
                    q.push(edges[u][i]);
            }
        }
        printf("%d",result[0]);
        for(int i = 1; i < result.size(); i++)
            printf(" %d",result[i]);
        printf("\n");
    }
    return 0;
}
