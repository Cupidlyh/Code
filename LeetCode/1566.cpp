class Solution {
public:
    //判断数组arr在[s,e)范围内是否由K个字符串[s,s+m)组成
    bool istrue(vector<int>& arr, int m,int s,int e) {
        for (int i = s + m; i < e; i++) {
            if(arr[i] != arr[i - m])
                return false;
        }
        return true;
    }


    bool containsPattern(vector<int>& arr, int m, int k) {
        int p = arr.size();
        int n = m * k;
        if (p - n < 0)
            return false;
        //暴力枚举
        for (int i = 0; i <= p - n; i++) {
            int sta = i;
            int end = i + n;
            if (istrue(arr,m,sta,end)) {
                return true;
            }
        }
        return false;
    }
};
