class Solution {
public:
    double ex = 1e-6;//精度
    double tag = 24;//目标值

    bool dfs(vector<double> &nums) {
        //边界条件： 没有选择了，直接返回
        if (nums.size() == 0)
            return false;
        //基线条件： 只有一种选择，直接判断结果
        if (nums.size() == 1)
            return abs(tag - nums[0]) < ex;
        //当前能做的选择:挑 2 个数，进行 4 种运算
        for (int i = 0; i < nums.size(); i++) {//挑选第一个数
            for (int j = 0; j < nums.size(); j++) {//挑选第二个数
                if (i == j)
                    continue;
                //保存剩余元素
                vector<double> curnums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        curnums.emplace_back(nums[k]);
                }
                bool isok;
                //尝试每一种运算
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
