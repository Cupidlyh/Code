class Solution {
public:
    #define MAXN 40005
    #define N 10005

    struct Edge//边结构体
    {
        int next;//与第i条边同一起点的上一条边的位置
        int to;//此边的终点
        double len;//边的权值
    } edge[MAXN];

    int head[N];//以i为起点的第一条边存储的位置（实际是最后输入的那个编号）
    int index;//若有多组例子，要在主函数里对它进行重新置为零的初始化

    bool vis[N];//用来标记点是否在队列中
    double length[N];//记录从起点到点n的路径的概率

    void add(int start,int end,double len)//链式前向星的加边函数
    {
        edge[index].len = len;
        edge[index].to = end;
        edge[index].next = head[start];
        head[start] = index++;
    }

    //最短路SPFA算法
    void SPFA(int start,int n) {//start是起始节点，n是节点总数
        memset(vis,0,sizeof(vis));
        memset(length,0,sizeof(length));
        queue<int>que;
        que.push(start);//入队
        vis[start] = true;//标记此点入队列
        length[start] = 1;//源点到源点的概率为1
        while(!que.empty()) {
            int u = que.front();
            que.pop();//出队
            vis[u] = false;//标记此点已经不在队列中
            for(int j = head[u]; j >= 0; j = edge[j].next) {//遍历与u联通的点
                int v = edge[j].to;
                if(length[v] < length[u] * edge[j].len) {
                    length[v] = length[u] * edge[j].len;//路径概率更新
                    if(vis[v] == 0) {//如果v点不在队列中
                        que.push(v);//入队
                        vis[v] = 1;//标记
                    }
                }
            }
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        memset(head,-1,sizeof(head));
        index = 0;
        for(int i = 0; i < edges.size(); i++) {
            add(edges[i][0],edges[i][1],succProb[i]);
            add(edges[i][1],edges[i][0],succProb[i]);
        }
        SPFA(start,n);//n为有向图顶点数，0为源点（由题意来输入源点,本代码点的编号是[0,n)）
        return length[end];
    }
};
