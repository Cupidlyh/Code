class Solution {
public:
    int res;
    int row;
    int n1,k1;

    void dfs(int n,vector<vector<int>>& relation,int m) {//n是目标编号，m是传递的轮数
        int i;
        if(m > k1)//轮数大于目标轮数
            return ;

        if(n == n1 - 1 && m == k1) {//符合条件
            res++;//结果加一
            return ;
        }

        for(i = 0; i < row; i++) {
            if(relation[i][0] == n) {//起点等于上一步的终点(目标编号)
                dfs(relation[i][1],relation,m + 1);
            }
        }
        return ;
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        res = 0;
        n1 = n;
        k1 = k;
        row = relation.size();
        for(int i = 0; i < row; i++) {
            if(relation[i][0] == 0) {
                dfs(relation[i][1],relation,1);
            }
        }
        return res;
    }
};
