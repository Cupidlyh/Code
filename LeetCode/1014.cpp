class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        //mx记录从前到后A[i]+i的最大值
        int mx = A[0],i,j,res = A[0];
        //景点需满足i<j,每次景点的最大值就是找前面的A[i]+i的最大值
        for(i = 1; i < A.size(); i++) {
            res = max(res,mx + A[i] - i);
            mx = max(mx,A[i] + i);
        }
        return res;
    }
};
