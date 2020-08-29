class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        //num��¼ÿ�����������Ĵ���,sta��ÿ���׶ε����,end��ÿ���׶ε��յ�
        int num[105] = {0};
        int sta,end;
        //ģ���������ɵĹ��̣�����¼ÿ�����������Ĵ���
        sta = rounds[0];
        end = rounds[1];
        if(end < sta) {
            for(int j = sta; j <= n; j++)
                num[j]++;
            for(int j = 1; j <= end; j++)
                num[j]++;
        }
        else {
            for(int j = sta; j <= end; j++)
                num[j]++;
        }
        for(int i = 1; i < rounds.size() - 1; i++) {
            sta = rounds[i] + 1;
            end = rounds[i + 1];
            if(end < sta) {
                for(int j = sta; j <= n; j++)
                    num[j]++;
                for(int j = 1; j <= end; j++)
                    num[j]++;
            }
            else {
                for(int j = sta; j <= end; j++)
                    num[j]++;
            }
        }
        //�ҳ������еľ����������ֵ
        int maxx = 0;
        for(int i = 1; i <= n; i++)
            maxx = max(maxx,num[i]);
        vector<int>res;
        //�����������������ֵ�Ĵ浽�����
        for(int i = 1; i <= n; i++)
            if(num[i] == maxx)
                res.push_back(i);
        return res;
    }
};
