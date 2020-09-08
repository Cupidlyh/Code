class Solution {
public:
    //递归解法
    //玩家一的分数是正数，玩家二得到的分数是负数，turn的正负代表的是几号玩家
    //将两个玩家选择的分数相加如果最后的结果是正数就代表玩家一胜利
    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[end] * turn;
        }
        //当前玩家选择头元素和尾元素的情况
        int chooseHead = nums[start] * turn + total(nums,start + 1,end,-turn);
        int chooseTail = nums[end] * turn + total(nums,start,end - 1,-turn);
        //返回大的那一种情况
        return max(chooseHead * turn,chooseTail * turn) * turn;
    }

    bool PredictTheWinner(vector<int>& nums) {
        return total(nums,0,nums.size() - 1,1) >= 0;
    }
};
