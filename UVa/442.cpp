#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
using namespace std;

struct node//�洢��������������
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
        scanf("%d %d",&d[m].x,&d[m].y);//�浽��Ӧ�±��λ��
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
            if(s[i] >= 'A' && s[i] <= 'Z')//������ĸ����ջ��
                sta.push(d[s[i] - 'A']);
            if(s[i] == ')')//����������
            {
                //��ջ��ȡ����������
                node aa = sta.top();
                sta.pop();
                node bb = sta.top();
                sta.pop();
                if(bb.y != aa.x)//������˾�����
                {
                    flag = 0;
                    break;
                }
                else
                {
                    sta.push({bb.x,aa.y});//��˺���¾���������������浽ջ��
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
