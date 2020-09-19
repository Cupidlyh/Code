class Solution {
public:
    //直接暴力遍历就可以了
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    int flag = 1;
                    for (int k = 0; k < mat.size(); k++) {
                        if (k == i)
                            continue;
                        if (mat[k][j] == 1) {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) {
                        for (int k = 0; k < mat[i].size(); k++) {
                            if (k == j)
                                continue;
                            if (mat[i][k] == 1) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if (flag)
                        res++;
                }
            }
        }
        return res;
    }
};
