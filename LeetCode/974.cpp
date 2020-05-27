class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;//记录每个总和对K求余后余数出现的次数
        mp[0] = 1;
        int sum = 0,res = 0,i;//sum记录A[0]到A[i]的和对K求余后的余数
        for(i = 0; i < A.size(); i++) {
            sum = ((sum + A[i]) % K + K) % K;//余数要保证全为正数，方便下面计算
            //pre[i]为A[0]到A[i]的和，则sum(i,j) = pre[j] - pre[i - 1];
            //若(pre[j] - pre[i - 1]) % k == 0,那么由同余定理可知
            //pre[j] % k == pre[i - 1] % k
            if(mp.find(sum) != mp.end())
                res += mp[sum];
            mp[sum]++;
        }
        return res;
    }
};
