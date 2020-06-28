class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left = 0,right = 0;//左右指针(左右都包括)
        int sum = nums[0],ans = INT_MAX;
        while(left <= right && right < nums.size()) {
            if(sum < s) {//小于s右指针向右移
                right++;
                if(right >= nums.size())
                    break;
                sum += nums[right];
            }
            else {//大于等于s左指针向右移
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
