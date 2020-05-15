class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int bit[100005] = {0},i = 0,j;
        for(j = 0; j < nums.size(); j++) {
            if(nums[j] == 1) {//�����е�1���±�浽bit������
                bit[i++] = j;
            }
        }
        for(j = 1; j < i; j++) {
            if(bit[j] - bit[j - 1] - 1 < k)//1���±�֮��Ҫ���ڵ���k
                return false;
        }
        return true;
    }
};
