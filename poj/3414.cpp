#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


//FiLL用-1表示，DROP用-2表示，POUR不表示
int main()
{
    int A,B,C;
    while (scanf("%d %d %d",&A,&B,&C) != EOF)
    {
        int book[105][105] = {0};//标记数组
        //记录当前A，B盆中的状态的路径（是由什么状态到达此A，B状态）
        vector<vector<pair<int,int> > > path(105,vector<pair<int,int> >(105));
        //记录是进行怎么样的操作才到达的此状态
        vector<vector<pair<int,int> > > dict(105,vector<pair<int,int> >(105));
        queue<pair<int,int> > q;
        q.push({0,0});
        book[0][0] = 1;
        int AA = 0,BB = 0;
        //广度优先搜索
        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (a == C || b == C)
            {
                AA = a;
                BB = b;
                break;
            }
            int aa,bb;
            //FiLL(1)
            if (a != A)
            {
                aa = A;
                bb = b;
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {-1,1};
                    path[aa][bb] = {a,b};
                }
            }
            //DROP(1);
            if (a != 0)
            {
                aa = 0;
                bb = b;
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {-2,1};
                    path[aa][bb] = {a,b};
                }
            }
            //POUR(1,2)
            if (a != 0 && b != B)
            {
                if (a <= B - b)
                {
                    aa = 0;
                    bb = b + a;
                }
                else
                {
                    aa = a - (B - b);
                    bb = B;
                }
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {1,2};
                    path[aa][bb] = {a,b};
                }
            }
            //FiLL(2)
            if (b != B)
            {
                bb = B;
                aa = a;
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {-1,2};
                    path[aa][bb] = {a,b};
                }
            }
            //DROP(2);
            if (b != 0)
            {
                bb = 0;
                aa = a;
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {-2,2};
                    path[aa][bb] = {a,b};
                }
            }
            //POUR(2,1)
            if (b != 0 && a != A)
            {
                if (b <= A - a)
                {
                    bb = 0;
                    aa = a + b;
                }
                else
                {
                    bb = b - (A - a);
                    aa = A;
                }
                if (!book[aa][bb])
                {
                    book[aa][bb] = 1;
                    q.push({aa,bb});
                    dict[aa][bb] = {2,1};
                    path[aa][bb] = {a,b};
                }
            }
        }
        //六种操作存储起来
        vector<string> temp;
        temp.push_back("FILL(1)");
        temp.push_back("FILL(2)");
        temp.push_back("DROP(1)");
        temp.push_back("DROP(2)");
        temp.push_back("POUR(1,2)");
        temp.push_back("POUR(2,1)");
        vector<string> res;//存储操作的结果
        vector<pair<int,int> > ress;//存储路径的坐标
        ress.push_back({AA,BB});
        while (true)
        {
            //aa,bb是路径的坐标
            int aa = ress.back().first;
            int bb = ress.back().second;
            if (aa == 0 && bb == 0)
                break;
            //fir,sec是操作
            int fir = dict[aa][bb].first;
            int sec = dict[aa][bb].second;
            if (fir == -1)
            {
                if (sec == 1)
                {
                    res.push_back(temp[0]);
                }
                if (sec == 2)
                {
                    res.push_back(temp[1]);
                }
            }
            else if (fir == -2)
            {
                if (sec == 1)
                {
                    res.push_back(temp[2]);
                }
                if (sec == 2)
                {
                    res.push_back(temp[3]);
                }
            }
            else
            {
                if (sec == 1)
                {
                    res.push_back(temp[5]);
                }
                if (sec == 2)
                {
                    res.push_back(temp[4]);
                }
            }
            ress.push_back(path[aa][bb]);
        }
        reverse(res.begin(),res.end());
        if (res.size() == 0)
            printf("impossible\n");
        else
        {
            printf("%d\n",res.size());
            for (int i = 0; i < res.size(); i++)
                printf("%s\n",res[i].c_str());
        }
    }
    return 0;
}
