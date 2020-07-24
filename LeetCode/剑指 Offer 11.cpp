class Solution {
public:
    int minArray(vector<int>& numbers) {
        int mid;
        int left = 0,right = numbers.size() - 1;
        //¶ş·Ö²éÕÒ
        while(left < right) {
            mid = left + (right - left) / 2;
            if(numbers[right] > numbers[mid]) {
                right = mid;
            }
            else if(numbers[right] < numbers[mid]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};
