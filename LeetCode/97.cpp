class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())//���Ȳ���ʱֱ�ӷ���false
            return false;
        //dp[i][j]��ʾs1��ǰi���ַ���s2��ǰj���ַ��ܷ񽻲����s3ǰi+j���ַ�
        vector<vector<int>> dp(s1.length() + 1,vector<int>(s2.length() + 1,0));
        dp[0][0] = 1;//ǰ0���ַ��϶��ǿ���ƥ���
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if(i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
                if(j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
