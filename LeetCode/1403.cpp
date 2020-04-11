class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums;
        sort(nums.begin(),nums.end());//��С��������
        int i,j;
        int sum = 0,sum1 = 0;
        for(i = nums.size() - 1; i >= 0; i--) {//�������ܺ�
            sum += nums[i];
        }
        for(i = nums.size() - 1; i >= 0; i--) {
            sum1 += nums[i];//�����еĺ�
            sum -= nums[i];
            if(sum1 > sum)
                break;
        }
        vector<int>res;
        for(j = nums.size() - 1; j >= i; j--)
            res.push_back(nums[j]);
        return res;
    }
};
