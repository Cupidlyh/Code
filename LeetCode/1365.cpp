#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>res;
        int i,j,num;
        for(i = 0; i < nums.size(); i++) {
            num = 0;
            for(j = 0; j < nums.size(); j++) {
                if(i == j)
                    continue;
                if(nums[i] > nums[j])
                    num++;
            }
            res.push_back(num);
        }
        return res;
    }
};
