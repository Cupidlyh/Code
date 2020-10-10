class Solution {
public:
    int specialArray(vector<int>& nums) {
        int book[1001] = {0};
        int maxx = 0;
        for (int i = 0; i < nums.size(); i++) {
            book[nums[i]]++;
            maxx = max(maxx,nums[i]);
        }
        for (int i = 0; i <= maxx; i++) {
            int num = 0;
            for (int j = i; j < 1001; j++) {
                num += book[j];
                if (num > i)
                    break;
            }
            if (num == i)
                return i;
        }
        return -1;
    }
};
