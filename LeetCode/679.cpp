class Solution {
public:
    double ex = 1e-6;//����
    double tag = 24;//Ŀ��ֵ

    bool dfs(vector<double> &nums) {
        //�߽������� û��ѡ���ˣ�ֱ�ӷ���
        if (nums.size() == 0)
            return false;
        //���������� ֻ��һ��ѡ��ֱ���жϽ��
        if (nums.size() == 1)
            return abs(tag - nums[0]) < ex;
        //��ǰ������ѡ��:�� 2 ���������� 4 ������
        for (int i = 0; i < nums.size(); i++) {//��ѡ��һ����
            for (int j = 0; j < nums.size(); j++) {//��ѡ�ڶ�����
                if (i == j)
                    continue;
                //����ʣ��Ԫ��
                vector<double> curnums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        curnums.emplace_back(nums[k]);
                }
                bool isok;
                //����ÿһ������
                //a + b
                curnums.emplace_back(nums[i] + nums[j]);
                isok = dfs(curnums);
                curnums.pop_back();
                if (isok)
                    return true;
                //a - b
                curnums.emplace_back(nums[i] - nums[j]);
                isok = dfs(curnums);
                curnums.pop_back();
                if (isok)
                    return true;
                //a * b
                curnums.emplace_back(nums[i] * nums[j]);
                isok = dfs(curnums);
                curnums.pop_back();
                if (isok)
                    return true;
                //a / b
                if (nums[j] != 0) {
                    curnums.emplace_back(nums[i] / nums[j]);
                    isok = dfs(curnums);
                    curnums.pop_back();
                    if (isok)
                        return true;
                }

            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> curnums;
        for (int i = 0; i < nums.size(); i++) {
            curnums.emplace_back(double(nums[i]));
        }
        return dfs(curnums);
    }
};
