package leetcode72;

class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        //���ַ��� word1 �ĳ���Ϊ i���ַ��� word2 �ĳ���Ϊ j ʱ���� word1 ת��Ϊ word2 ��ʹ�õ����ٲ�������Ϊ dp[i] [j]
        int [][] dp = new int[n1 + 1][n2 + 1];
        int i,j;
        //��word1�ַ���Ϊ��ʱ��ֻ�ܽ��в������
        for(i = 1; i <= n2; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        //��word2�ַ���Ϊ��ʱ��ֻ�ܽ���ɾ������
        for(i = 1; i <= n1; i++)
            dp[i][0] = dp[i - 1][0] + 1;
        //���������ַ���
        for(i = 1; i <= n1; i++) {
            for(j = 1; j <= n2; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1))//�ַ���ȣ�����Ҫ�����κβ���
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;//��ɾ�������룬�滻��ѡ��һ����С��
            }
        }
        return dp[n1][n2];
    }
}
