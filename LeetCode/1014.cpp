class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        //mx��¼��ǰ����A[i]+i�����ֵ
        int mx = A[0],i,j,res = A[0];
        //����������i<j,ÿ�ξ�������ֵ������ǰ���A[i]+i�����ֵ
        for(i = 1; i < A.size(); i++) {
            res = max(res,mx + A[i] - i);
            mx = max(mx,A[i] + i);
        }
        return res;
    }
};
