class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int index1 = 0,index2 = numbers.size() - 1;
        //¼ò¼òµ¥µ¥Ë«Ö¸Õë
        while(index1 < index2) {
            if(numbers[index1] + numbers[index2] == target)
                break;
            else if(numbers[index1] + numbers[index2] < target) {
                index1++;
            }
            else if(numbers[index1] + numbers[index2] > target) {
                index2--;
            }
        }
        res.push_back(index1 + 1);
        res.push_back(index2 + 1);
        return res;
    }
};
