class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//��С��������
        int res = 1e7;//��¼���
        //�ȹ̶���һ��Ԫ�ص�λ�ã����ڴ�Ԫ�غ���������Ԫ��
        for(int i = 0; i < nums.size() - 2; i++) {//i��λ����һ��Ԫ�أ�������Ԫ����i֮��
            int left = i + 1,right = nums.size() - 1;//����ָ��
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];//���
                if(sum == target) {
                    return target;
                }
                else if(sum <= target) {//�ƶ���ָ���ʹ�ͱ��
                    if(abs(sum - target) < abs(res - target)) {//���½��
                        res = sum;
                    }
                    int l = nums[left];
                    while(left < nums.size() && nums[left] == l) {//�ƶ�ָ��ʱҪȥ��
                        left++;
                    }
                }
                else if(sum > target) {//�ƶ���ָ���ʹ�ͱ�С
                    if(abs(sum - target) < abs(res - target)) {//���½��
                        res = sum;
                    }
                    int r = nums[right];
                    while(right >= 0 && nums[right] == r) {//�ƶ�ָ��ʱҪȥ��
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
