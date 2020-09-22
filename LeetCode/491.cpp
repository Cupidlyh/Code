class Solution {
public:
    //存储递归回溯时的路径数值
    vector<int> temp;
    set<vector<int>> st;//用来去重

    void huisu(vector<int>& nums,int bit) {
        if (temp.size() >= 2) {
            st.insert(temp);
        }
        for (int i = bit; i < nums.size(); i++) {
            if (temp.size() == 0 || nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                huisu(nums,i + 1);
                temp.pop_back();
            }
        }
        return ;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        huisu(nums,0);
        vector<vector<int>> res(st.begin(),st.end());
        return res;
    }
};
