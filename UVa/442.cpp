#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
using namespace std;

struct node//存储矩阵行数和列数
{
    int x,y;
};

int main()
{
    int n,i,m;
    char ch;
    node d[26];
    scanf("%d",&n);
    getchar();
    for(i = 0; i < n; i++)
    {
        scanf("%c",&ch);
        m = ch - 'A';
        scanf("%d %d",&d[m].x,&d[m].y);//存到对应下标的位置
        getchar();
    }
    string s;
    while(cin>>s)
    {
        int sum = 0;
        stack<node> sta;
        int flag = 1;
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')//遇见字母存入栈中
                sta.push(d[s[i] - 'A']);
            if(s[i] == ')')//遇见右括号
            {
                //从栈顶取出两个矩阵
                node aa = sta.top();
                sta.pop();
                node bb = sta.top();
                sta.pop();
                if(bb.y != aa.x)//不能相乘就跳出
                {
                    flag = 0;
                    break;
                }
                else
                {
                    sta.push({bb.x,aa.y});//相乘后的新矩阵的行数和列数存到栈中
                    sum += bb.y * bb.x * aa.y;
                }
            }
        }
        if(flag == 0)
            printf("error\n");
        else
            printf("%d\n",sum);
    }
    return 0;
}
