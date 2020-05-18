class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dpmax(nums.size(),0);
        vector<int>dpmin(nums.size(),0);
        int i,maxx = nums[0];
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        //��Ϊ�����д��ڸ����������п��ܳ��ָ������������������Ҫ�����������¼�м�ֵ
        //�������鶯��̬�滮���̾���forѭ���еķ��̣�maxx��¼���ֵ
        for(i = 1; i < nums.size(); i++) {
            dpmin[i] = min(min(nums[i],nums[i] * dpmin[i - 1]),dpmax[i - 1] * nums[i]);
            dpmax[i] = max(max(nums[i],nums[i] * dpmax[i - 1]),dpmin[i - 1] * nums[i]);
            maxx = max(maxx,dpmax[i]);
        }
        return maxx;
    }
};
