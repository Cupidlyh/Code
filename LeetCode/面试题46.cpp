class Solution {
public:
    int translateNum(int num) {
        if(num == 0)
            return 1;
        int numm[12],dp[12];//numm�洢ÿһλ�����֣�dp[i]��ʾ���ֵ�iλ������i��֮ǰ������
        int bit = log10(num) + 1;//����num��λ��
        int i = bit - 1;
        while(num) {
            numm[i--] = num % 10;
            num /= 10;
        }
        dp[0] = 1;//һλ���϶��ǿ��Է����һ��
        //֮�����ж�̬�滮����ǰ���ֺ�ǰһλ������ɵ������Ƿ����25
        //����25��dp[i] = dp[i-1]��С�ڵ���25��dp[i] = dp[i-1]+dp[i-2];
        if(bit >= 2 && numm[0] * 10 + numm[1] <= 25)
            dp[1] = 2;
        else
            dp[1] = 1;
        for(i = 2; i <= bit - 1; i++) {
            if(numm[i - 1] != 0 && numm[i - 1] * 10 + numm[i] <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[bit - 1];
    }
};
