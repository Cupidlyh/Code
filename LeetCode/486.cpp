class Solution {
public:
    //�ݹ�ⷨ
    //���һ�ķ�������������Ҷ��õ��ķ����Ǹ�����turn������������Ǽ������
    //���������ѡ��ķ������������Ľ���������ʹ������һʤ��
    int total(vector<int>& nums, int start, int end, int turn) {
        if (start == end) {
            return nums[end] * turn;
        }
        //��ǰ���ѡ��ͷԪ�غ�βԪ�ص����
        int chooseHead = nums[start] * turn + total(nums,start + 1,end,-turn);
        int chooseTail = nums[end] * turn + total(nums,start,end - 1,-turn);
        //���ش����һ�����
        return max(chooseHead * turn,chooseTail * turn) * turn;
    }

    bool PredictTheWinner(vector<int>& nums) {
        return total(nums,0,nums.size() - 1,1) >= 0;
    }
};
