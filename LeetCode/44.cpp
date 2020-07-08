class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        //dp[i][j]��ʾ�ַ���s��ǰi���ַ���ģʽp��ǰj���ַ��Ƿ���ƥ��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        //������ַ�������ƥ��
        dp[0][0] = 1;
        //��Ϊ'*'��ƥ����ַ��������Կ�ͷ������'*'�ǿ���ƥ��sǰ0���ַ�
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = 1;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];//�����㣨'*'ƥ��պ������ַ������������
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
