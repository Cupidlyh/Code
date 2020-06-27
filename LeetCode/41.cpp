class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //n = nums.size(),与[0,n)对应的可以存最多是[1-n]的这些正整数，所以我们对数组元素进行交换
        for(int i = 0; i < nums.size(); i++) {
            //i位置存放除了[1,n]中的元素或者就是对应位置的元素(i+1)或者出现与交换元素重复就跳出循环
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i] && nums[i] != i + 1) {
                swap(nums[i],nums[nums[i] - 1]);
            }
        }
        //遍历每个位置是否是对应元素(0位置应该存放1，1存放2……)
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};
