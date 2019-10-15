package leetcode;

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int i,j;
        int[] dp = new int[target+1];//�Զ����������Ԫ�س�ʼ��Ϊ0
        dp[0]=1;//Ϊ����������Ԫ�ص���target�������
        for(i=1;i<=target;i++) {
            for(j=0;j<nums.length;j++) {
                if(i-nums[j]>=0)//����Ϊ����nums�������ҳ���Ϊtarget�����
                    dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
        return dp[target];
    }
}
