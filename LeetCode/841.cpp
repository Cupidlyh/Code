class Solution {
public:
    vector<int> set;//标记数组
    int num;
    //深度优先搜索
    void dfs(vector<vector<int>>& rooms,int n) {
        num++;
        set[n] = 1;
        for (int i = 0; i < rooms[n].size(); i++) {
            if(set[rooms[n][i]] == 0) {
                dfs(rooms,rooms[n][i]);
            }
        }
        return ;
    }

    //拿完此房间的钥匙就等于我们可以随时随地进出此房间
    //所以可以深搜我们可以进入的房间数量是否等于总房间数目
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set.resize(rooms.size());
        num = 0;
        dfs(rooms,0);
        return num == rooms.size();
    }
};
