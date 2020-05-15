class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        int maxx,minn;
        int left = 0,right = 1;//˫ָ�빹�ɵ�����ҿ��Ĵ���
        //�������������С����ֵ�Ĳ�ֵ������limit���Ǵ�������������Ԫ��֮�������limit
        //��ʼ���ֵ��Сֵ���ǵ�һ��Ԫ��
        maxx = nums[left];
        minn = nums[left];
        while(left < nums.size() && right <= nums.size() && left < right) {//ѭ������
            if(maxx - minn <= limit) {
                res = max(right - left,res);//�������������鳤��(ȡ���ֵ)
                right++;//���䳤�ȼ�1
                if(right > nums.size())//�±겻��Խ��
                    continue;
                //���������Сֵ
                maxx = maxx > nums[right - 1] ? maxx : nums[right - 1];
                minn = minn < nums[right - 1] ? minn : nums[right - 1];
            }
            else {
                while(maxx - minn > limit && left < nums.size() && right <= nums.size() && left < right) {//ѭ������
                    left++;//���䳤�ȼ�1
                    if(left >= nums.size())//�±겻��Խ��
                        continue;
                    if(nums[left - 1] != maxx && nums[left - 1] != minn)//���ֵ��Сֵû�仯
                        continue;
                    if(nums[left - 1] == maxx) {//���ֵ��ɾ����
                        maxx = 0;
                        for(int i = left; i < right; i++) {//��[left,right)��������Ѱ�����ֵ
                            maxx = max(maxx,nums[i]);
                        }
                    }
                    if(nums[left - 1] == minn) {//��Сֵ��ɾ����
                        minn = INT_MAX;
                        for(int i = left; i < right; i++) {//��[left,right)��������Ѱ����Сֵ
                            minn = min(minn,nums[i]);
                        }
                    }
                }
            }
        }
        return res;
    }
};
