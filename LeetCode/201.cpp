class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            //Ä¨È¥×îÓÒ±ßµÄ 1
            n = n & (n - 1);
        }
        return n;
    }
};
