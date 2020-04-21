class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd[nums.size() + 2],ans = 0,cnt = 1,i;
        for (i = 0; i < nums.size(); i++) {//将奇数出现的下标存储在odd中
            if (nums[i] % 2 != 0)
                odd[cnt++] = i;
        }
        odd[0] = -1;
        odd[cnt] = nums.size();
        int left,right;//记录区间左边偶数数量和右边偶数数量
        for (i = 1; i + k <= cnt; i++) {
            left = odd[i] - odd[i - 1] - 1;
            right = odd[i + k] - odd[i + k - 1] - 1;
            ans += 1 + left + right + left * right;
        }
        return ans;
    }
};
