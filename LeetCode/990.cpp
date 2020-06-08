class Solution {
public:
    int father[1000];//��¼���ڵ�

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

    bool equationsPossible(vector<string>& equations) {
        int i;
        string temp;
        for(i = 0; i < 1000; i++)//��ʼ��
            father[i] = i;
        for(i = 0; i < equations.size(); i++) {
            temp = equations[i];
            if(temp[1] == '=')
                Union(temp[0] - 26,temp[3] - 26);//�ϲ�
        }
        for(i = 0; i < equations.size(); i++) {
            temp = equations[i];
            if(temp[1] == '!') {
                if(Query(temp[0] - 26,temp[3] - 26))//��ѯ
                    return false;
            }
        }
        return true;
    }
};
