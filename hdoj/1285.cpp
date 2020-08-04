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
        return c>r.c;//先返回序号小的
    }
};

int main()
{
    int N,M;
    while(scanf("%d %d",&N,&M) != EOF)
    {
        int p1,p2;
        // 存储有向图
        vector<vector<int> > edges;
        // 存储每个节点的入度
        vector<int> indeg;
        // 存储答案
        vector<int> result;
        edges.resize(N + 1);
        indeg.resize(N + 1);
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d",&p1,&p2);
            edges[p1].push_back(p2);
            indeg[p2]++;
        }
        //优先队列存储入度为0的点（即为正确的排名顺序）
        priority_queue<qnode> q;
        for(int i = 1; i < indeg.size(); i++)
        {
            if(indeg[i] == 0)//入度为0的点先存进队列中
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.top().c;
            q.pop();
            result.push_back(u);
            for(int i = 0; i < edges[u].size(); i++)  //u点为去除掉的点，所以要将从u点来的入度减1
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
