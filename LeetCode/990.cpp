class Solution {
public:
    int father[1000];//记录父节点

    int Find(int x)//查询x的根节点并路径压缩
    {
        if(father[x] != x)
            father[x] = Find(father[x]);
        return father[x];
    }

    void Union(int x,int y)//合并x和y的集合
    {
        int rx,ry;
        rx=Find(x);
        ry=Find(y);
        if(rx!=ry)
            father[rx]=ry;
    }

    bool Query(int a,int b)//查询a和b是否在同一集合
    {
        return Find(a) == Find(b);//二者根节点相同即为在同一集合
    }

    bool equationsPossible(vector<string>& equations) {
        int i;
        string temp;
        for(i = 0; i < 1000; i++)//初始化
            father[i] = i;
        for(i = 0; i < equations.size(); i++) {
            temp = equations[i];
            if(temp[1] == '=')
                Union(temp[0] - 26,temp[3] - 26);//合并
        }
        for(i = 0; i < equations.size(); i++) {
            temp = equations[i];
            if(temp[1] == '!') {
                if(Query(temp[0] - 26,temp[3] - 26))//查询
                    return false;
            }
        }
        return true;
    }
};
