class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n,INT_MAX / 2));//����m��n�г�ʼֵΪ�������ֵ��һ��
        int i,j;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(matrix[i][j] == 0)//Ԫ��0�����0�ľ������0
                    res[i][j] = 0;
        //ֻ��ˮƽ�����ƶ�����ֱ�����ƶ�
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++) {
                if(i - 1 >= 0)//�����浽i,jλ��
                    res[i][j] = min(res[i][j],res[i - 1][j] + 1);
                if(j - 1 >= 0)//�����浽i,jλ��
                    res[i][j] = min(res[i][j],res[i][j - 1] + 1);
            }
        //ֻ��ˮƽ�����ƶ�����ֱ�����ƶ�
        for(i = m - 1; i >= 0; i--)
            for(j = n - 1; j >= 0; j--) {
                if(i + 1 < m)//�����浽i,jλ��
                    res[i][j] = min(res[i][j],res[i + 1][j] + 1);
                if(j + 1 < n)//�����浽i,jλ��
                    res[i][j] = min(res[i][j],res[i][j + 1] + 1);
            }
        return res;
    }
};
