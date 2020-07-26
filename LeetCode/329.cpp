class Solution {
public:
    int cool[4][2] = {0,1,0,-1,-1,0,1,0};//��������
    int row,col;

    //���仯�����������
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>& res) {
        for(int i = 0; i < 4; i++) {//ֻ�����������ƶ�
            int x = r + cool[i][0];
            int y = c + cool[i][1];
            if(x < 0 || y < 0 || x >= row || y >= col)//Խ��
                continue;
            if(matrix[x][y] <= matrix[r][c])//Ѱ�ҵ��ǵ���·��
                continue;
            if(res[x][y] != 0) {//���仯��������һ������0����ֱ���ù�����
                res[r][c] = max(res[r][c],1 + res[x][y]);//ȡ���ֵ
            }
            else {//��0�Ļ���Ҫ���������������
                res[r][c] = max(res[r][c],1 + dfs(x,y,matrix,res));//ȡ
            }
        }
        if(res[r][c] == 0)//ÿ������������һ������
            res[r][c] = 1;
        return res[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        row = matrix.size();
        col = matrix[0].size();
        int ans = 0;
        //��¼ÿ����Ԫ��������·���ĳ���
        vector<vector<int>> res(row,vector<int>(col,0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dfs(i,j,matrix,res);
                ans = max(ans,res[i][j]);//�����ֵ
            }
        }
        return ans;
    }
};
