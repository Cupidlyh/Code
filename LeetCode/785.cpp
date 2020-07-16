class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vis[105] = {0},flag = 1;//�������ͼ��ϱ��
        int A[105] = {0},B[105] = {0};//���ִ洢�ļ���
        queue<int> q;
        int k = 0;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].size() == 0) {//�����ĵ�ȫ�浽A����
                vis[i] = 1;
                A[i] = 1;
            }
            else {
                k = i;
            }
        }
        q.push(k);
        q.push(-1);//-1��Ŀ����Ϊ�˽���浽��ͬ������
        //�����������
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(t == -1) {
                if(q.empty()) {
                    int f = 1,i;
                    for(i = 0; i < graph.size(); i++) {//ͼ�����е㶼�߹������˳�ѭ��
                        if(!vis[i]) {
                            f = 0;
                            break;
                        }
                    }
                    if(f)
                        break;
                    q.push(i);//δ�������ĵ���������
                }
                q.push(-1);
                flag *= -1;
                continue;
            }
            if(flag == 1) {//�����ڼ����н��б��
                A[t] = 1;
            }
            else {
                B[t] = 1;
            }
            vis[t] = 1;//����Ѿ��߹�
            for(int i = 0; i < graph[t].size(); i++) {
                if(!vis[graph[t][i]]) {//��t��������û�߹��ӵ�������
                    q.push(graph[t][i]);
                }
            }
        }
        for(int i = 0; i < 105; i++) {
            if(A[i] && B[i])
                return false;
        }
        return true;
    }
};
