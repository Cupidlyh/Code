#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<int>temp;
        vector<vector<int>>res;
        int left = 1;//左指针
        int right = 1;//右指针
        int sum = 1;//和（左右指针都包括）
        while(left <= target / 2) {//因为求的是连续正整数（所以左指针小于target的一半）
            if(sum < target) {//当和小于target
                right++;//右指针加一
                sum = sum + right;//求和
            }
            else if(sum > target) {//当和大于target
                sum = sum - left;//求和
                left++;//左指针加一
            }
            else {//当和等于target
                for(int i = left; i <= right; i++) {
                    temp.push_back(i);//将结果存进temp
                }
                res.push_back(temp);//将temp存进res
                temp.clear();//清空temp
                //计算下一种情况
                sum = sum - left;
                left++;
            }
        }
        return res;
    }
};
