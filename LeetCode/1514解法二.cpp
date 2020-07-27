class Solution {
public:
    #define MAXN 40005
    #define N 10005
    struct qnode//根据c值的大小，c值大的先出队列
    {
        int v;
        double c;
        qnode(int _v = 0,double _c = 0):v(_v),c(_c) {}
        bool operator <(const qnode &r)const
        {
            return c < r.c;
        }
    };
    struct Edge
    {
        int v;//终点
        double cost;//起点到终点v遍历成功的概率（图中的信息）
        Edge(int _v = 0,double _cost = 0):v(_v),cost(_cost) {}
    };
    vector<Edge> E[MAXN];//存储图的信息
    bool vis[MAXN];//标记数组
    double dist[MAXN];//记录起始点到当前下标的概率
    //Dijkstar算法 + 堆优化
    void Dijkstra(int n,int start)//点的编号从0开始
    {
        //初始化
        memset(vis,false,sizeof(vis));
        for(int i = 0; i < n; i++)
            dist[i] = 0;
        priority_queue<qnode> que;//优先队列
        while(!que.empty())
            que.pop();
        dist[start] = 1;//起点到起点的概率为1
        que.push(qnode(start,1));
        qnode tmp;
        while(!que.empty())
        {
            tmp = que.top();
            que.pop();
            int u = tmp.v;
            if(vis[u])
                continue;
            vis[u] = true;
            //遍历与之联通的点
            for(int i = 0; i < E[u].size(); i++)
            {
                int v = E[tmp.v][i].v;
                double cost = E[u][i].cost;
                if(!vis[v] && dist[v] < dist[u] * cost)
                {
                    dist[v] = dist[u] * cost;//路径更新
                    que.push(qnode(v,dist[v]));

                }
            }
        }
    }
    //建图
    void addedge(int u,int v,double w)
    {
        E[u].push_back(Edge(v,w));
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i = 0; i < edges.size(); i++) {
            addedge(edges[i][0],edges[i][1],succProb[i]);
            addedge(edges[i][1],edges[i][0],succProb[i]);
        }
        //n是点的个数，start是起点
        Dijkstra(n,start);
        return dist[end];
    }
};
