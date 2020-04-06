class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size(),i,j,res = 0;
        int small[205] = {0},big[205] = {0};//��¼�ڵ�ǰԪ�غ��Ԫ�����ж��ٱȵ�ǰԪ��С�ʹ��
        for(i = 0; i < len; i++) {//ͳ��Ԫ�صĴ�С
            for(j = i + 1; j < len; j++) {
                if(rating[j] > rating[i])
                    big[i]++;
                if(rating[j] < rating[i])
                    small[i]++;
            }
        }
        //rating[i] < rating[j] < rating[k]
        for(i = 0; i <= len - 3; i++) {
            for(j = i + 1; j <= len - 2; j++) {
                if(rating[i] < rating[j]) {
                    res += big[j];
                }
            }
        }
        //rating[i] > rating[j] > rating[k]
        for(i = 0; i <= len - 3; i++) {
            for(j = i + 1; j <= len - 2; j++) {
                if(rating[i] > rating[j]) {
                    res += small[j];
                }
            }
        }
        return res;
    }
};
