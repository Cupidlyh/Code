class Solution {
public:
    int n,m;

    vector<vector<int>> bfs(int x, int y, vector<string>& maze) {
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//��������
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
        // �洢���� & ʯͷ������
        vector<pair<int, int>> buttons, stones;
        // ��¼��� & �յ������
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
        // ��¼��㵽������ľ���
        vector<vector<int>> start_dist = bfs(sx, sy, maze);
        // �߽������û�л���
        if (nb == 0) {
            return start_dist[tx][ty];
        }
        // ��ĳ�����ص��������� / ������յ����̾���
        // dist[i][nb] ��ʾ�� ����i �� ��� ����̾���
        // dist[i][nb+1] ��ʾ�� ����i �� �յ� ����̾���
        vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
        // �м���
        vector<vector<vector<int>>> dd(nb);
        for (int i = 0; i < nb; i++) {
            // ����i�Ű�ť�����е����̾���
            vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
            dd[i] = d;
            // ��ĳ���㵽�յ㲻��Ҫ��ʯͷ
            dist[i][nb + 1] = d[tx][ty];// i�Ű�ť���յ�ľ���
        }
        for (int i = 0; i < nb; i++) {
            int tmp = -1;
            // �ҳ���㵽ĳһ��ʯ���ٵ�i�Ű�ť����̾���
            for (int k = 0; k < ns; k++) {
                int mid_x = stones[k].first, mid_y = stones[k].second;
                // i�Ű�ť�����ߵ�k��ʯͷ���������Ե�k��ʯͷ
                if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {
                    if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
                        tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                    }
                }
            }
            //i�Ż��ص����ľ��루;��ĳһ��ʯ�ѣ�
            dist[i][nb] = tmp;
            // �ҳ�i�Ű�ť��ĳ��ʯ���ٵ�j�Ű�ť����̾���
            for (int j = i + 1; j < nb; j++) {
                int mn = -1;
                for (int k = 0; k < ns; k++) {
                    int mid_x = stones[k].first, mid_y = stones[k].second;
                    // i�Ű�ť�����ߵ�k��ʯͷ����j�Ű�ť�����ߵ�k��ʯͷ
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
        // �޷���ɵ�����(��ĿҪ����㵽�յ���Ҫ�������л���)
        // ֻҪ��һ�����ش���㲻�ɴ�����޷������յ㣬�ͷ���-1
        for (int i = 0; i < nb; i++) {
            if (dist[i][nb] == -1 || dist[i][nb + 1] == -1)
                return -1;
        }
        // dp ���飬 -1 ����û�б�����
        // dp[mask][j]���ߵ���ǰ״̬�����ٲ�������ǰ״̬Ϊ���ڵ� j �����ش������صĴ���״̬Ϊ mask
        vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
        for (int i = 0; i < nb; i++) {
            dp[1 << i][i] = dist[i][nb];
        }
        //mask�Ƕ���������ÿһλ����һ����ť�Ĵ���״̬
        // ���ڸ��µ�״̬����δ���µĴ�����ֱ�Ӵ�С�����������
        for (int mask = 1; mask < (1 << nb); mask++) {
            for (int i = 0; i < nb; i++) {
                // ��ǰ dp �ǺϷ���
                if (mask & (1 << i)) {
                    for (int j = 0; j < nb; j++) {
                        // j ���� mask ��
                        if (!(mask & (1 << j))) {
                            //��j�Ű�ť��Ϊ����״̬
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
        // ����ȫ������
        int final_mask = (1 << nb) - 1;
        // �ҵ�һ����ĳ���ص����ڵ���̾���(�����Ѿ�ȫ�������������ȫ����������̲���)
        for (int i = 0; i < nb; i++) {
            if (res == -1 || res > dp[final_mask][i] + dist[i][nb + 1]) {
                res = dp[final_mask][i] + dist[i][nb + 1];
            }
        }
        return res;
    }
};
