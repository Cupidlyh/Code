class Solution {
public:
    int n,m;

    vector<vector<int>> bfs(int x, int y, vector<string>& maze) {
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        vector<vector<int>> arr(n, vector<int>(m, -1));
        arr[x][y] = 0;
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()) {
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = xx + coor[i][0];
                int col = yy + coor[i][1];
                if (row >= n || col >= m || row < 0 || col < 0)
                    continue;
                if (arr[row][col] == -1 && maze[row][col] != '#') {
                    arr[row][col] = arr[xx][yy] + 1;
                    q.push({row,col});
                }
            }
        }
        return arr;
    }

    int minimalSteps(vector<string>& maze) {
        n = maze.size();
        m = maze[0].size();
        // 存储机关 & 石头的坐标
        vector<pair<int, int>> buttons, stones;
        // 记录起点 & 终点的坐标
        int sx, sy, tx, ty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'M') {
                    buttons.push_back({i, j});
                }
                if (maze[i][j] == 'O') {
                    stones.push_back({i, j});
                }
                if (maze[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (maze[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }
        int nb = buttons.size();
        int ns = stones.size();
        // 记录起点到其他点的距离
        vector<vector<int>> start_dist = bfs(sx, sy, maze);
        // 边界情况：没有机关
        if (nb == 0) {
            return start_dist[tx][ty];
        }
        // 从某个机关到其他机关 / 起点与终点的最短距离
        // dist[i][nb] 表示从 机关i 到 起点 的最短距离
        // dist[i][nb+1] 表示从 机关i 到 终点 的最短距离
        vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
        // 中间结果
        vector<vector<vector<int>>> dd(nb);
        for (int i = 0; i < nb; i++) {
            // 计算i号按钮到所有点的最短距离
            vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
            dd[i] = d;
            // 从某个点到终点不需要拿石头
            dist[i][nb + 1] = d[tx][ty];// i号按钮到终点的距离
        }
        for (int i = 0; i < nb; i++) {
            int tmp = -1;
            // 找出起点到某一处石堆再到i号按钮的最短距离
            for (int k = 0; k < ns; k++) {
                int mid_x = stones[k].first, mid_y = stones[k].second;
                // i号按钮可以走到k号石头并且起点可以到k号石头
                if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {
                    if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
                        tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                    }
                }
            }
            //i号机关到起点的距离（途径某一处石堆）
            dist[i][nb] = tmp;
            // 找出i号按钮到某处石堆再到j号按钮的最短距离
            for (int j = i + 1; j < nb; j++) {
                int mn = -1;
                for (int k = 0; k < ns; k++) {
                    int mid_x = stones[k].first, mid_y = stones[k].second;
                    // i号按钮可以走到k号石头并且j号按钮可以走到k号石头
                    if (dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
                        if (mn == -1 || mn > dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]) {
                            mn = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];
                        }
                    }
                }
                dist[i][j] = mn;
                dist[j][i] = mn;
            }
        }
        // 无法达成的情形(题目要求起点到终点需要经过所有机关)
        // 只要有一个机关从起点不可达，或者无法到达终点，就返回-1
        for (int i = 0; i < nb; i++) {
            if (dist[i][nb] == -1 || dist[i][nb + 1] == -1)
                return -1;
        }
        // dp 数组， -1 代表没有遍历到
        // dp[mask][j]：走到当前状态的最少步数。当前状态为：在第 j 个机关处，机关的触发状态为 mask
        vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
        for (int i = 0; i < nb; i++) {
            dp[1 << i][i] = dist[i][nb];
        }
        //mask是二进制数，每一位代表一个按钮的触发状态
        // 由于更新的状态都比未更新的大，所以直接从小到大遍历即可
        for (int mask = 1; mask < (1 << nb); mask++) {
            for (int i = 0; i < nb; i++) {
                // 当前 dp 是合法的
                if (mask & (1 << i)) {
                    for (int j = 0; j < nb; j++) {
                        // j 不在 mask 里
                        if (!(mask & (1 << j))) {
                            //将j号按钮变为触发状态
                            int next = mask | (1 << j);
                            if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
                                dp[next][j] = dp[mask][i] + dist[i][j];
                            }
                        }
                    }
                }
            }
        }
        int res = -1;
        // 机关全部触发
        int final_mask = (1 << nb) - 1;
        // 找到一条从某机关到出口的最短距离(机关已经全部触发并算出了全部触发的最短步数)
        for (int i = 0; i < nb; i++) {
            if (res == -1 || res > dp[final_mask][i] + dist[i][nb + 1]) {
                res = dp[final_mask][i] + dist[i][nb + 1];
            }
        }
        return res;
    }
};
