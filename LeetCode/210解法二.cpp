class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标0为栈底
    vector<int> result;
    // 判断有向图中是否有环
    bool invalid;

public:
    void dfs(int u) {
        visited[u] = 1;//将结点标记为搜索中
        int i;
        for(i = 0; i < edges[u].size(); i++) {
            //如果未搜索那么搜索相邻节点
            if(visited[edges[u][i]] == 0) {
                dfs(edges[u][i]);
            }
            //如果找到了另外的结点在搜索中就说明找到了环
            else if(visited[edges[u][i]] == 1) {
                invalid = true;
                return ;
            }
        }
        visited[u] = 2;//将节点标记为已完成
        result.push_back(u);//压进栈中
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        int i;
        for(i = 0; i < prerequisites.size(); i++) {//构建有向图并存储每个结点的入度值
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // 每次挑选一个未搜索的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && !invalid; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        if (invalid) {
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};