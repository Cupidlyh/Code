class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // �洢����ͼ
        vector<vector<int>> edges;
        // �洢ÿ���ڵ�����
        vector<int> indeg;
        edges.resize(numCourses);
        indeg.resize(numCourses);
        int i;
        for(i = 0; i < prerequisites.size(); i++) {//��������ͼ���洢ÿ���������ֵ
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;//���д洢���Ϊ0�ĵ㣨��Ϊ��ȷ��ѧϰ˳��
        for(i = 0; i < indeg.size(); i++) {
            if(indeg[i] == 0)//���Ϊ0�ĵ��ȴ��������
                q.push(i);
        }
        int num = 0;//��¼����ѧϰ�Ŀγ�����
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            num++;
            for(i = 0; i < edges[u].size(); i++) {//u��Ϊȥ�����ĵ㣬����Ҫ����u��������ȼ�1
                indeg[edges[u][i]]--;
                if(indeg[edges[u][i]] == 0)
                    q.push(edges[u][i]);
            }
        }
        if (num != numCourses) {//�жϿ���ѧϰ�Ľ�����Ƿ������֪�����
            return false;
        }
        return true;
    }
};
