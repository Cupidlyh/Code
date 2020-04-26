class Solution {
public:
    int res;
    int row;
    int n1,k1;

    void dfs(int n,vector<vector<int>>& relation,int m) {//n��Ŀ���ţ�m�Ǵ��ݵ�����
        int i;
        if(m > k1)//��������Ŀ������
            return ;

        if(n == n1 - 1 && m == k1) {//��������
            res++;//�����һ
            return ;
        }

        for(i = 0; i < row; i++) {
            if(relation[i][0] == n) {//��������һ�����յ�(Ŀ����)
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
