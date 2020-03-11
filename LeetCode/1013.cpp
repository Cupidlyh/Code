#include <iostream>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0,i;
        for(i = 0; i < A.size(); i++)//将数组中的元素求和
            sum = sum + A[i];
        if(sum % 3 != 0)//和不能被3整除
            return false;//不能分成和相等的三部分
        int sum1 = 0,num = 0;
        for(i = 0; i < A.size(); i++) {
            sum1 += A[i];
            if(sum1 == sum / 3) {//sum / 3 就是三部分每一部分的和
                sum1 = 0;//和归零
                num++;//记录出现了几部分和为sum/3
            }
            if(num == 2)//出现了两个部分
                break;
        }
        if(i < A.size() - 1)
            return true;
        return false;
    }
};
