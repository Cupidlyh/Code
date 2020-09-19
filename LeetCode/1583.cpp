class Solution {
public:
    //�ж�x�Ƿ�᲻����
    bool unhappy(int x,int y,int u,int v,vector<vector<int>>& newpre) {
        if (newpre[x][u] > newpre[x][y] && newpre[u][x] > newpre[u][v]) {
            return true;
        }
        return false;
    }

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        if (n == 2)
            return 0;
        int res = 0;
        //��¼�����׽���ϵ
        vector<vector<int>> newpre(preferences.size(),vector<int>(n + 5,0));
        //��Ǵ������Ƿ񲻿���
        vector<int> st(n,0);
        //�����ֵĴ�С����ʾ�����׽���ϵ������
        for (int i = 0; i < preferences.size(); i++) {
            int rate = 1000;
            for (int j = 0; j < preferences[i].size(); j++) {
                newpre[i][preferences[i][j]] = rate--;
            }
        }
        //��¼���ѱ��
        int x,y,u,v;
        //ֱ�ӱ�����������������жϾͿ�����
        for (int i = 0; i < pairs.size() - 1; i++) {
            for (int j = i + 1; j < pairs.size(); j++) {
                x = pairs[i][0];
                y = pairs[i][1];
                u = pairs[j][0];
                v = pairs[j][1];
                if (!st[x]) {
                    if (unhappy(x,y,u,v,newpre)) {
                        st[x] = 1;
                    }
                    if (!st[x]) {
                        if (unhappy(x,y,v,u,newpre)) {
                            st[x] = 1;
                        }
                    }
                }
                if (!st[y]) {
                    if (unhappy(y,x,v,u,newpre)) {
                        st[y] = 1;
                    }
                    if (!st[y]) {
                        if (unhappy(y,x,u,v,newpre)) {
                            st[y] = 1;
                        }
                    }
                }
                if (!st[u]) {
                    if (unhappy(u,v,x,y,newpre)) {
                        st[u] = 1;
                    }
                    if (!st[u]) {
                        if (unhappy(u,v,y,x,newpre)) {
                            st[u] = 1;
                        }
                    }
                }
                if (!st[v]) {
                    if (unhappy(v,u,y,x,newpre)) {
                        st[v] = 1;
                    }
                    if (!st[v]) {
                        if (unhappy(v,u,x,y,newpre)) {
                            st[v] = 1;
                        }
                    }
                }
            }
        }
        //ͳ�Ʋ��������ѵ���Ŀ
        for (int i = 0; i < n; i++) {
            if (st[i])
                res++;
        }
        return res;

    }
};
