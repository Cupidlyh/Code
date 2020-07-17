class Solution {
public:
    int father[105];//记录父节点

    int Find(int x) {//查询x的根节点并路径压缩
        if(father[x] != x)
            father[x] = Find(father[x]);
        return father[x];
    }

    void Union(int x,int y) {//合并x和y的集合
        int rx,ry;
        rx=Find(x);
        ry=Find(y);
        if(rx!=ry)
            father[rx]=ry;
    }

    bool Query(int a,int b) {//查询a和b是否在同一集合
        return Find(a) == Find(b);//二者根节点相同即为在同一集合
    }

    bool isBipartite(vector<vector<int>>& graph) {
        for(int i = 0; i < 105; i++)//初始化并查集
            father[i] = i;
        // 遍历每个顶点，将当前顶点的所有邻接点进行合并
        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                Union(graph[i][0],graph[i][j]);
                // 若某个邻接点与当前顶点已经在一个集合中了，说明不是二分图，返回 false
                if(Query(i,graph[i][j]))
                    return false;
            }
        }
        return true;
    }
};