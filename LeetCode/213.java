package leetcode213;

public class Solution {
	public int rob(int[] nums) {
        if(nums.length == 1)//ֻ��һ������ʱ
            return nums[0];
        int dp[] = new int[nums.length + 2];//Ĭ�ϳ�ʼ��Ϊ0
        int dp1[] = new int[nums.length + 2];

        for (int i = 1; i < nums.length; i++)//ȥ��nums��ͷԪ���ٱ���nums����
            dp[i + 2] = Math.max(dp[i] + nums[i], dp[i + 1]);//��̬����

        for (int i = 0; i < nums.length - 1; i++)//ȥ��nums��βԪ�ر���nums����
            dp1[i + 2] = Math.max(dp1[i] + nums[i], dp1[i + 1]);
        
        return Math.max(dp[nums.length + 1],dp1[nums.length]);//�ڵ��Ե�һ�����ݺͲ����Ե�һ�����������������ѡ��һ�����
    }
}
