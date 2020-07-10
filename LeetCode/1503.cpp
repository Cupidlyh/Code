class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        //找向左爬的蚂蚁中落地最晚的
        for(int i = 0; i < left.size(); i++)
            res = max(res,left[i]);
        //找向右爬的蚂蚁中落地最晚的
        for(int i = 0; i < right.size(); i++)
            res = max(res,n - right[i]);
        return res;
    }
};
