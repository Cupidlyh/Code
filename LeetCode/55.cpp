class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0;//��¼��ǰ���Ե��������±�ֵ
        for (int i = 0; i < n; i++) {
            if (i <= maxx) {//�±�С�ڵ�ǰ����±�ֵ��ζ�ſ��Ե���
                maxx = max(maxx, i + nums[i]);//������󵽴��±�ֵ
                if (maxx >= n - 1) {//�������鳤��
                    return true;
                }
            }
        }
        return false;
    }
};
