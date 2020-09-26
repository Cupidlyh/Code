class Solution {
public:
    long res = -1;
    int row,col;
    int temp = 1000000007;

    //深度优先搜索
    void dfs(vector<vector<int>>& grid,int r,int c,long num) {
        if (r == row - 1 && c == col - 1) {
            res = max(res,num);
            return ;
        }
        if (num == 0) {
            res = max(res,num);
            return ;
        }
        if (c + 1 < col) {
            dfs(grid,r,c + 1,(num * grid[r][c + 1]));
        }
        if (r + 1 < row) {
            dfs(grid,r + 1,c,(num * grid[r + 1][c]));
        }
        return ;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        dfs(grid,0,0,grid[0][0]);
        if (res < 0)
            return -1;
        return res % temp;
    }
};
