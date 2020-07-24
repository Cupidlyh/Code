class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid;
        int left = 0,right = nums.size() - 1;
        //¶ş·Ö²éÕÒ
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[right] > nums[mid]) {
                right = mid;
            }
            else if(nums[right] < nums[mid]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};
