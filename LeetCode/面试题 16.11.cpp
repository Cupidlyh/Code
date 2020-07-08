class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k == 0)//ʹ��ľ�����Ϊ0
            return res;
        if(shorter == longer) {//����ľ�峤��һ��
            res.push_back(shorter * k);
            return res;
        }
        //���������С�������������ʼֻʹ�ö�ľ�壬
        //֮�����ÿ��һ����ľ�壬�Ͷ�һ����ľ��
        int nums = k,numl = 0,num;
        while(nums != -1) {
            num = nums * shorter + numl * longer;
            res.push_back(num);
            nums--;
            numl++;
        }
        return res;
    }
};
