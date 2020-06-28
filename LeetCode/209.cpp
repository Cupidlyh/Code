class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left = 0,right = 0;//����ָ��(���Ҷ�����)
        int sum = nums[0],ans = INT_MAX;
        while(left <= right && right < nums.size()) {
            if(sum < s) {//С��s��ָ��������
                right++;
                if(right >= nums.size())
                    break;
                sum += nums[right];
            }
            else {//���ڵ���s��ָ��������
                ans = min(ans,right - left + 1);
                sum -= nums[left];
                left++;
                if(left >= nums.size())
                    break;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
