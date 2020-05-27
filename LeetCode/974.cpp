class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp;//��¼ÿ���ܺͶ�K������������ֵĴ���
        mp[0] = 1;
        int sum = 0,res = 0,i;//sum��¼A[0]��A[i]�ĺͶ�K����������
        for(i = 0; i < A.size(); i++) {
            sum = ((sum + A[i]) % K + K) % K;//����Ҫ��֤ȫΪ�����������������
            //pre[i]ΪA[0]��A[i]�ĺͣ���sum(i,j) = pre[j] - pre[i - 1];
            //��(pre[j] - pre[i - 1]) % k == 0,��ô��ͬ�ඨ���֪
            //pre[j] % k == pre[i - 1] % k
            if(mp.find(sum) != mp.end())
                res += mp[sum];
            mp[sum]++;
        }
        return res;
    }
};
