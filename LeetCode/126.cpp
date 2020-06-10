class Solution {
public:
    vector<vector<int>>edges;//存储点和点之间的关系
    vector<vector<string>>res;//结果
    vector<int>lay;//存储每个点的层次
    vector<string>te;
    int endid;//endWord的编号

    int diff(string &s1,string &s2) {//判断两个字符串是否不同字母只有一个
        int dif = 0;
        for (int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                dif++;
            if(dif > 1)
                return dif;
        }
        return dif;
    }

    void dfs(int preid,vector<string> &wordList) {
        if (preid == endid) {//到达endWord
            res.push_back(te);//存进结果中
            return ;
        }
        for (int i = 0; i < edges[preid].size(); i++) {
            if (lay[edges[preid][i]] == lay[preid] + 1) {//在下一层寻找单词
                te.push_back(wordList[edges[preid][i]]);
                dfs(edges[preid][i],wordList);
                te.pop_back();
            }
        }
        return ;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int i,j;
        int beginid = -1;
        endid = -1;
        edges.resize(wordList.size() + 10);
        //建图(单词在wordList的位置就是单词的编号)
        for (i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord)
                endid = i;
            if(wordList[i] == beginWord)
                beginid = i;
            for (j = i + 1; j < wordList.size(); j++) {
                if (diff(wordList[i], wordList[j]) == 1) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        if (endid == -1)//wordList中不含有endWord
            return {};
        if (beginid == -1) {//如果wordList中不含有beginWord
            beginid = wordList.size();//编号
            for(i = 0; i < wordList.size(); i++) {
                if(diff(beginWord,wordList[i]) == 1) {
                    edges[i].push_back(beginid);
                    edges[beginid].push_back(i);
                }
            }
            wordList.push_back(beginWord);//存到wordList中
        }
        lay.resize(wordList.size() + 10,-1);
        queue<int> q;
        q.push(beginid);
        lay[beginid] = 0;
        while (!q.empty()) {//利用BFS存储每个点的层次
            int temp = q.front();
            q.pop();
            for (i = 0; i < edges[temp].size(); i++) {
                if (lay[edges[temp][i]] == -1) {
                    lay[edges[temp][i]] = lay[temp] + 1;
                    q.push(edges[temp][i]);
                }
            }
        }
        te.push_back(beginWord);
        //回溯
        dfs(beginid,wordList);//深度优先搜索
        return res;
    }
};
