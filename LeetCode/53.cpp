class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0,maxx = nums[0];
        //��̬�滮����dp[i] = max(dp[i-1] + nums[i],nums[i])
        //dp[i]�����Ե�i������β�����������������,���ս��������dp������ѡ�����ֵ
        //�۲췽�̷��ֿ��Ա�ɿռ�����Ϊ1��д�������£�
        for(int i = 0; i < nums.size(); i++) {
            prev = max(prev + nums[i],nums[i]);
            maxx = max(prev,maxx);
        }
        return maxx;
    }
};
