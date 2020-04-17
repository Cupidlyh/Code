class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0;//记录当前可以到达的最大下标值
        for (int i = 0; i < n; i++) {
            if (i <= maxx) {//下标小于当前最大下标值意味着可以到达
                maxx = max(maxx, i + nums[i]);//更新最大到达下标值
                if (maxx >= n - 1) {//超出数组长度
                    return true;
                }
            }
        }
        return false;
    }
};
