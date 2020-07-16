class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vis[105] = {0},flag = 1;//标记数组和集合标记
        int A[105] = {0},B[105] = {0};//数字存储的集合
        queue<int> q;
        int k = 0;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].size() == 0) {//独立的点全存到A集合
                vis[i] = 1;
                A[i] = 1;
            }
            else {
                k = i;
            }
        }
        q.push(k);
        q.push(-1);//-1的目的是为了将点存到不同集合中
        //广度优先搜索
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(t == -1) {
                if(q.empty()) {
                    int f = 1,i;
                    for(i = 0; i < graph.size(); i++) {//图中所有点都走过才能退出循环
                        if(!vis[i]) {
                            f = 0;
                            break;
                        }
                    }
                    if(f)
                        break;
                    q.push(i);//未遍历到的点加入队列中
                }
                q.push(-1);
                flag *= -1;
                continue;
            }
            if(flag == 1) {//数字在集合中进行标记
                A[t] = 1;
            }
            else {
                B[t] = 1;
            }
            vis[t] = 1;//标记已经走过
            for(int i = 0; i < graph[t].size(); i++) {
                if(!vis[graph[t][i]]) {//与t点相连且没走过加到队列中
                    q.push(graph[t][i]);
                }
            }
        }
        for(int i = 0; i < 105; i++) {
            if(A[i] && B[i])
                return false;
        }
        return true;
    }
};
