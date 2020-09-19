class Solution {
public:
    //判断x是否会不开心
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
        //记录朋友亲近关系
        vector<vector<int>> newpre(preferences.size(),vector<int>(n + 5,0));
        //标记此朋友是否不开心
        vector<int> st(n,0);
        //用数字的大小来表示朋友亲近关系的排名
        for (int i = 0; i < preferences.size(); i++) {
            int rate = 1000;
            for (int j = 0; j < preferences[i].size(); j++) {
                newpre[i][preferences[i][j]] = rate--;
            }
        }
        //记录朋友编号
        int x,y,u,v;
        //直接暴力法根据题意进行判断就可以了
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
        //统计不开心朋友的数目
        for (int i = 0; i < n; i++) {
            if (st[i])
                res++;
        }
        return res;

    }
};
