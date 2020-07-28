class Solution {
public:
    bool check(vector<int>& nums,int m,int mid) {
        //��ǰ����nums���л��֣�ʹ��������� <= mid��Ȼ��ͳ����������������������
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            }
            else
                sum += nums[i];
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        //��С�ͱ�Ȼ���� [max(nums), sum(nums)] ֮��
        //left��ʾ���������䣬��ʼֵΪmax(nums)
        //right��ʾ���������䣬��ʼֵΪsum(nums)
        long long left = 0,right = 0;
        for(int i = 0; i < nums.size(); i++) {
            right += nums[i];
            left = left > nums[i] ? left : nums[i];
        }
        //������ѡ��midֵ��С������������������ > m��Ŀ��ֵӦ���� [mid+1, right]
        //������ѡ��midֵ�������������������� <= m��Ŀ��ֵӦ���� [left, mid]
        while(left < right) {//���ֲ���
            int mid = (left + right) / 2;
            if(check(nums,m,mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
