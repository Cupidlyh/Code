class Solution {
public:
    int dp[1000005];

    int waysToChange(int n) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int i,j,arr[4] = {25,10,5,1};
        //��һ��forѭ��������ÿ������ЩӲ�����Ǯ��
        //һ��ʼֻ��25����һ����25,10����һ����25,10,5����һ����25,10,5,1���������Ա�֤û���ظ��ģ�
        for(i = 0; i < 4; i++) {
            int temp = arr[i];
            for(j = temp; j <= n; j++)
                dp[j] = (dp[j] + dp[j - temp]) % 1000000007;
        }
        return dp[n];
    }
};
