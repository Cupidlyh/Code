class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string res = paths[0][1];//旅行终点站一定不是起点
        int map[105] = {0},i;//map为标记paths数组第i行是否遍历过
        map[0] = 1;
        while(true) {
            int flag = 1;
            for(i = 0; i < paths.size(); i++) {
                if(map[i] == 1) {
                    continue;
                }
                if(paths[i][0] == res) {//非终点站的定义是可以通过当前城市(起点)到另一个城市(终点)
                    flag = 0;
                    map[i] = 1;
                    res = paths[i][1];
                    break;
                }
            }
            if(flag)//flag为1代表此时的地点为终点站(你不能从终点站到任何城市)
                break;
        }
        return res;
    }
};
