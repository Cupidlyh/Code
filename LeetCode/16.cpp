class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//从小到大排序
        int res = 1e7;//记录结果
        //先固定好一个元素的位置，再在此元素后找另两个元素
        for(int i = 0; i < nums.size() - 2; i++) {//i的位置是一个元素，另两个元素在i之后
            int left = i + 1,right = nums.size() - 1;//左右指针
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];//求和
                if(sum == target) {
                    return target;
                }
                else if(sum <= target) {//移动左指针会使和变大
                    if(abs(sum - target) < abs(res - target)) {//更新结果
                        res = sum;
                    }
                    int l = nums[left];
                    while(left < nums.size() && nums[left] == l) {//移动指针时要去重
                        left++;
                    }
                }
                else if(sum > target) {//移动右指针会使和变小
                    if(abs(sum - target) < abs(res - target)) {//更新结果
                        res = sum;
                    }
                    int r = nums[right];
                    while(right >= 0 && nums[right] == r) {//移动指针时要去重
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
