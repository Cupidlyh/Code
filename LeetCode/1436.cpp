class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string res = paths[0][1];//�����յ�վһ���������
        int map[105] = {0},i;//mapΪ���paths�����i���Ƿ������
        map[0] = 1;
        while(true) {
            int flag = 1;
            for(i = 0; i < paths.size(); i++) {
                if(map[i] == 1) {
                    continue;
                }
                if(paths[i][0] == res) {//���յ�վ�Ķ����ǿ���ͨ����ǰ����(���)����һ������(�յ�)
                    flag = 0;
                    map[i] = 1;
                    res = paths[i][1];
                    break;
                }
            }
            if(flag)//flagΪ1�����ʱ�ĵص�Ϊ�յ�վ(�㲻�ܴ��յ�վ���κγ���)
                break;
        }
        return res;
    }
};
