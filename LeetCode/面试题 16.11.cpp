class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k == 0)//使用木板个数为0
            return res;
        if(shorter == longer) {//两种木板长度一样
            res.push_back(shorter * k);
            return res;
        }
        //返回数组从小到大，所以我们最开始只使用短木板，
        //之后就是每少一个短木板，就多一个长木板
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
