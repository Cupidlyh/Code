class Solution {
public:
    #define M 1005
    int father[M];//��¼���ڵ�

    int Find(int x)//��ѯx�ĸ��ڵ㲢·��ѹ��
    {
        if(father[x] != x)
            father[x] = Find(father[x]);
        return father[x];
    }

    void Union(int x,int y)//�ϲ�x��y�ļ���
    {
        int rx,ry;
        rx=Find(x);
        ry=Find(y);
        if(rx!=ry)
            father[rx]=ry;
    }

    bool Query(int a,int b)//��ѯa��b�Ƿ���ͬһ����
    {
        return Find(a) == Find(b);//���߸��ڵ���ͬ��Ϊ��ͬһ����
    }

    //�ж�ɾ��edges[n][0]��edges[n][1]���ӵı߻᲻��ʹͼ�ֳ�������
    //�������ֳ���������˵���˱߾��Ǹ��ӱߣ���ĿҪ����ʹ��ʣ�µ�ͼ����N���ڵ���и�����
    bool samefather(vector<vector<int>>& edges,int n) {
        for (int i = 0; i < M; i++)
            father[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            if (i == n)
                continue;
            Union(edges[i][0],edges[i][1]);
        }
        if (Query(edges[n][0],edges[n][1]))
            return true;
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> in(edges.size() + 1);//���
        //1.ĳ����������Ϊ2����ô��˵����������һ����һ���Ǹ��ӱ�
        for (int i = 0; i < edges.size(); i++) {
            in[edges[i][1]].push_back(i);
            if (in[edges[i][1]].size() == 2) {
                if (samefather(edges,in[edges[i][1]][1]))
                    return {edges[in[edges[i][1]][1]][0],edges[in[edges[i][1]][1]][1]};
                else
                    return {edges[in[edges[i][1]][0]][0],edges[in[edges[i][1]][0]][1]};
            }
        }
        //2.���е���ȶ�Ϊ1���ͳɻ��ˣ����Ծͱ����Ӻ���ǰ�ң���ĿҪ�����ж���𰸣������������ڸ�����ά����Ĵ𰸡���
        for (int i = edges.size() - 1; i >= 0; i--){
            if (samefather(edges,i))
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};
