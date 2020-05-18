class Solution {
public:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        int i;
        for(i = 0; i < prerequisites.size(); i++) {//构建有向图并存储每个结点的入度值
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;//队列存储入度为0的点（即为正确的学习顺序）
        for(i = 0; i < indeg.size(); i++) {
            if(indeg[i] == 0)//入度为0的点先存进队列中
                q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(i = 0; i < edges[u].size(); i++) {//u点为去除掉的点，所以要将从u点来的入度减1
                indeg[edges[u][i]]--;
                if(indeg[edges[u][i]] == 0)
                    q.push(edges[u][i]);
            }
        }
        if (result.size() != numCourses) {//判断结果中的结点数是否等于已知结点数
            return {};
        }
        return result;
    }
};
