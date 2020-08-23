class Solution {
public:
    /*思路如下：
    **数组元素奇数个，将所有元素变成正中间的那个值，
    **比如有[1,3,5]这三个元素，则需要将所有元素变成3
    **数组元素偶数个，将所有元素变成正中间的那两个值的平均值，
    **比如有[1,3,5,7]这三个元素，则需要将所有元素变成(3+5)/2=4
    */
    int minOperations(int n) {
        int res = 0;
        if(n % 2 == 0) {
            int m = n / 2 - 1;
            int temp = 1 + 1 + (2 * m);
            for(int i = 0; i <= m; i++)
                res += temp - ((2 * i) + 1);
        }
        else {
            int m = n / 2;
            int temp = 1 + (2 * m);
            for(int i = 0; i < m; i++)
                res += temp - ((2 * i) + 1);
        }
        return res;
    }
};
