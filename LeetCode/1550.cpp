class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int num = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 == 0) {
                num = 0;
            }
            else {
                num++;
                if(num == 3)
                    return true;
            }
        }
        return false;
    }
};
