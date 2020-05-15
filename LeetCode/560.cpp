class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;//记录每个总和出现的次数
        mp[0] = 1;
        int res = 0,sum = 0;//sum记录num[0]到nums[i]的和
        //假设pre[i]为[0..i]里所有数的和，则pre[i]可以由pre[i−1]递推而来，pre[i]=pre[i−1]+nums[i]
        //那么[j..i]这个子数组和为k这个条件我们可以转化为pre[i]−pre[j−1]==k，再进行转化为pre[j−1]==pre[i]−k
        //所以我们就可以在当前元素之前的所有前缀和中找是否有等于pre[i]−k的，有几个等的就加几个到结果中
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())
                res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};
