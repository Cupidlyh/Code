#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);//将n进行标记
        while(true) {
            int m = 0;
            while(n != 0) {//计算平方和
                m += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = m;
            if(n == 1)//最后为1即为快乐数
                return true;
            if(s.find(n) != s.end())//如果此数已经被标记过了，意味着陷入无限循环，就不是快乐数
                break;
            s.insert(n);//标记n
        }
        return false;
    }
};
