#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());//��С��������
        return nums[nums.size() / 2];//��Ϊ�ܴ���Ԫ�ش���n/2������ֱ�ӷ����м䴦���±�
    }
};
