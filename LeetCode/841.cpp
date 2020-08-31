class Solution {
public:
    vector<int> set;//�������
    int num;
    //�����������
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

    //����˷����Կ�׾͵������ǿ�����ʱ��ؽ����˷���
    //���Կ����������ǿ��Խ���ķ��������Ƿ�����ܷ�����Ŀ
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set.resize(rooms.size());
        num = 0;
        dfs(rooms,0);
        return num == rooms.size();
    }
};
