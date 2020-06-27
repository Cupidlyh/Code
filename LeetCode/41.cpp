class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //n = nums.size(),��[0,n)��Ӧ�Ŀ��Դ������[1-n]����Щ���������������Ƕ�����Ԫ�ؽ��н���
        for(int i = 0; i < nums.size(); i++) {
            //iλ�ô�ų���[1,n]�е�Ԫ�ػ��߾��Ƕ�Ӧλ�õ�Ԫ��(i+1)���߳����뽻��Ԫ���ظ�������ѭ��
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i] && nums[i] != i + 1) {
                swap(nums[i],nums[nums[i] - 1]);
            }
        }
        //����ÿ��λ���Ƿ��Ƕ�ӦԪ��(0λ��Ӧ�ô��1��1���2����)
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};
