class Solution {
public:
    #define MAXN 40005
    #define N 10005

    struct Edge//�߽ṹ��
    {
        int next;//���i����ͬһ������һ���ߵ�λ��
        int to;//�˱ߵ��յ�
        double len;//�ߵ�Ȩֵ
    } edge[MAXN];

    int head[N];//��iΪ���ĵ�һ���ߴ洢��λ�ã�ʵ�������������Ǹ���ţ�
    int index;//���ж������ӣ�Ҫ�����������������������Ϊ��ĳ�ʼ��

    bool vis[N];//������ǵ��Ƿ��ڶ�����
    double length[N];//��¼����㵽��n��·���ĸ���

    void add(int start,int end,double len)//��ʽǰ���ǵļӱߺ���
    {
        edge[index].len = len;
        edge[index].to = end;
        edge[index].next = head[start];
        head[start] = index++;
    }

    //���·SPFA�㷨
    void SPFA(int start,int n) {//start����ʼ�ڵ㣬n�ǽڵ�����
        memset(vis,0,sizeof(vis));
        memset(length,0,sizeof(length));
        queue<int>que;
        que.push(start);//���
        vis[start] = true;//��Ǵ˵������
        length[start] = 1;//Դ�㵽Դ��ĸ���Ϊ1
        while(!que.empty()) {
            int u = que.front();
            que.pop();//����
            vis[u] = false;//��Ǵ˵��Ѿ����ڶ�����
            for(int j = head[u]; j >= 0; j = edge[j].next) {//������u��ͨ�ĵ�
                int v = edge[j].to;
                if(length[v] < length[u] * edge[j].len) {
                    length[v] = length[u] * edge[j].len;//·�����ʸ���
                    if(vis[v] == 0) {//���v�㲻�ڶ�����
                        que.push(v);//���
                        vis[v] = 1;//���
                    }
                }
            }
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        memset(head,-1,sizeof(head));
        index = 0;
        for(int i = 0; i < edges.size(); i++) {
            add(edges[i][0],edges[i][1],succProb[i]);
            add(edges[i][1],edges[i][0],succProb[i]);
        }
        SPFA(start,n);//nΪ����ͼ��������0ΪԴ�㣨������������Դ��,�������ı����[0,n)��
        return length[end];
    }
};
