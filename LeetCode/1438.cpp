class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        int maxx,minn;
        int left = 0,right = 1;//双指针构成的左闭右开的窗口
        //连续区间最大最小两个值的差值不超过limit，那此区间任意两个元素之差都不超过limit
        //初始最大值最小值都是第一个元素
        maxx = nums[left];
        minn = nums[left];
        while(left < nums.size() && right <= nums.size() && left < right) {//循环条件
            if(maxx - minn <= limit) {
                res = max(right - left,res);//更新连续子数组长度(取最大值)
                right++;//区间长度加1
                if(right > nums.size())//下标不能越界
                    continue;
                //更新最大最小值
                maxx = maxx > nums[right - 1] ? maxx : nums[right - 1];
                minn = minn < nums[right - 1] ? minn : nums[right - 1];
            }
            else {
                while(maxx - minn > limit && left < nums.size() && right <= nums.size() && left < right) {//循环条件
                    left++;//区间长度减1
                    if(left >= nums.size())//下标不能越界
                        continue;
                    if(nums[left - 1] != maxx && nums[left - 1] != minn)//最大值最小值没变化
                        continue;
                    if(nums[left - 1] == maxx) {//最大值被删除了
                        maxx = 0;
                        for(int i = left; i < right; i++) {//在[left,right)区间重新寻找最大值
                            maxx = max(maxx,nums[i]);
                        }
                    }
                    if(nums[left - 1] == minn) {//最小值被删除了
                        minn = INT_MAX;
                        for(int i = left; i < right; i++) {//在[left,right)区间重新寻找最小值
                            minn = min(minn,nums[i]);
                        }
                    }
                }
            }
        }
        return res;
    }
};
