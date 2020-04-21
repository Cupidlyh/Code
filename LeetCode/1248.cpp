class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd[nums.size() + 2],ans = 0,cnt = 1,i;
        for (i = 0; i < nums.size(); i++) {//���������ֵ��±�洢��odd��
            if (nums[i] % 2 != 0)
                odd[cnt++] = i;
        }
        odd[0] = -1;
        odd[cnt] = nums.size();
        int left,right;//��¼�������ż���������ұ�ż������
        for (i = 1; i + k <= cnt; i++) {
            left = odd[i] - odd[i - 1] - 1;
            right = odd[i + k] - odd[i + k - 1] - 1;
            ans += 1 + left + right + left * right;
        }
        return ans;
    }
};
