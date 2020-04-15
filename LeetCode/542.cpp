class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n,INT_MAX / 2));//开辟m行n列初始值为整形最大值的一半
        int i,j;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(matrix[i][j] == 0)//元素0到最近0的距离就是0
                    res[i][j] = 0;
        //只有水平向左移动和竖直向上移动
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++) {
                if(i - 1 >= 0)//从上面到i,j位置
                    res[i][j] = min(res[i][j],res[i - 1][j] + 1);
                if(j - 1 >= 0)//从左面到i,j位置
                    res[i][j] = min(res[i][j],res[i][j - 1] + 1);
            }
        //只有水平向右移动和竖直向下移动
        for(i = m - 1; i >= 0; i--)
            for(j = n - 1; j >= 0; j--) {
                if(i + 1 < m)//从下面到i,j位置
                    res[i][j] = min(res[i][j],res[i + 1][j] + 1);
                if(j + 1 < n)//从右面到i,j位置
                    res[i][j] = min(res[i][j],res[i][j + 1] + 1);
            }
        return res;
    }
};
