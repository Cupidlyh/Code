class Solution {
public:
    #define M 1005
    int father[M];//记录父节点

    int Find(int x)//查询x的根节点并路径压缩
    {
        if(father[x] != x)
            father[x] = Find(father[x]);
        return father[x];
    }

    void Union(int x,int y)//合并x和y的集合
    {
        int rx,ry;
        rx=Find(x);
        ry=Find(y);
        if(rx!=ry)
            father[rx]=ry;
    }

    bool Query(int a,int b)//查询a和b是否在同一集合
    {
        return Find(a) == Find(b);//二者根节点相同即为在同一集合
    }

    //判断删除edges[n][0]和edges[n][1]连接的边会不会使图分成两部分
    //如果不会分成两部分那说明此边就是附加边（题目要求是使得剩下的图是有N个节点的有根树）
    bool samefather(vector<vector<int>>& edges,int n) {
        for (int i = 0; i < M; i++)
            father[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            if (i == n)
                continue;
            Union(edges[i][0],edges[i][1]);
        }
        if (Query(edges[n][0],edges[n][1]))
            return true;
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> in(edges.size() + 1);//入度
        //1.某个点如果入度为2，那么入此点的两条边中一定有一个是附加边
        for (int i = 0; i < edges.size(); i++) {
            in[edges[i][1]].push_back(i);
            if (in[edges[i][1]].size() == 2) {
                if (samefather(edges,in[edges[i][1]][1]))
                    return {edges[in[edges[i][1]][1]][0],edges[in[edges[i][1]][1]][1]};
                else
                    return {edges[in[edges[i][1]][0]][0],edges[in[edges[i][1]][0]][1]};
            }
        }
        //2.所有点入度都为1，就成环了，所以就暴力从后往前找（题目要求若有多个答案，返回最后出现在给定二维数组的答案。）
        for (int i = edges.size() - 1; i >= 0; i--){
            if (samefather(edges,i))
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};
