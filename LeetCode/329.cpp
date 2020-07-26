class Solution {
public:
    int cool[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    int row,col;

    //记忆化深度优先搜索
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>& res) {
        for(int i = 0; i < 4; i++) {//只能上下左右移动
            int x = r + cool[i][0];
            int y = c + cool[i][1];
            if(x < 0 || y < 0 || x >= row || y >= col)//越界
                continue;
            if(matrix[x][y] <= matrix[r][c])//寻找的是递增路径
                continue;
            if(res[x][y] != 0) {//记忆化搜索，下一步不是0可以直接拿过来用
                res[r][c] = max(res[r][c],1 + res[x][y]);//取最大值
            }
            else {//是0的话还要继续深度优先搜索
                res[r][c] = max(res[r][c],1 + dfs(x,y,matrix,res));//取
            }
        }
        if(res[r][c] == 0)//每个格子自身算一个长度
            res[r][c] = 1;
        return res[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        row = matrix.size();
        col = matrix[0].size();
        int ans = 0;
        //记录每个单元格的最长递增路径的长度
        vector<vector<int>> res(row,vector<int>(col,0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dfs(i,j,matrix,res);
                ans = max(ans,res[i][j]);//找最大值
            }
        }
        return ans;
    }
};
