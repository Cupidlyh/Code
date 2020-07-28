class Solution {
public:
    bool check(vector<int>& nums,int m,int mid) {
        //由前向后对nums进行划分，使其子数组和 <= mid，然后统计满足条件的子数组数量
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            }
            else
                sum += nums[i];
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        //最小和必然落在 [max(nums), sum(nums)] 之间
        //left表示的是左区间，初始值为max(nums)
        //right表示的是右区间，初始值为sum(nums)
        long long left = 0,right = 0;
        for(int i = 0; i < nums.size(); i++) {
            right += nums[i];
            left = left > nums[i] ? left : nums[i];
        }
        //若我们选的mid值过小，则满足条件的数量 > m，目标值应落在 [mid+1, right]
        //若我们选的mid值过大，则满足条件的数量 <= m，目标值应落在 [left, mid]
        while(left < right) {//二分查找
            int mid = (left + right) / 2;
            if(check(nums,m,mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
