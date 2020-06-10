class Solution {
public:
    vector<vector<int>>edges;//�洢��͵�֮��Ĺ�ϵ
    vector<vector<string>>res;//���
    vector<int>lay;//�洢ÿ����Ĳ��
    vector<string>te;
    int endid;//endWord�ı��

    int diff(string &s1,string &s2) {//�ж������ַ����Ƿ�ͬ��ĸֻ��һ��
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
        if (preid == endid) {//����endWord
            res.push_back(te);//��������
            return ;
        }
        for (int i = 0; i < edges[preid].size(); i++) {
            if (lay[edges[preid][i]] == lay[preid] + 1) {//����һ��Ѱ�ҵ���
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
        //��ͼ(������wordList��λ�þ��ǵ��ʵı��)
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
        if (endid == -1)//wordList�в�����endWord
            return {};
        if (beginid == -1) {//���wordList�в�����beginWord
            beginid = wordList.size();//���
            for(i = 0; i < wordList.size(); i++) {
                if(diff(beginWord,wordList[i]) == 1) {
                    edges[i].push_back(beginid);
                    edges[beginid].push_back(i);
                }
            }
            wordList.push_back(beginWord);//�浽wordList��
        }
        lay.resize(wordList.size() + 10,-1);
        queue<int> q;
        q.push(beginid);
        lay[beginid] = 0;
        while (!q.empty()) {//����BFS�洢ÿ����Ĳ��
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
        //����
        dfs(beginid,wordList);//�����������
        return res;
    }
};
