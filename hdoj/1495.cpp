#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int s,n,m,t;
    node() {}
    node(int ss,int nn,int mm,int tt):s(ss),n(nn),m(mm),t(tt) {}
};


int main()
{
    int S,N,M;
    while (scanf("%d %d %d",&S,&N,&M) != EOF)
    {
        if (S == 0 && N == 0 && M == 0)
            break;
        //ȷ��S�����N���ڶ���M����С
        if (N < M)
        {
            int temp = N;
            N = M;
            M = temp;
        }
        //���s,n������ˮ��������������ӱ���ˣ�����������Ҳ�ͱ���ˣ������Ƕ�ά���飩
        int book[105][105] = {0};
        int res = 0;
        queue<node> q;
        q.push(node(S,0,0,0));
        book[S][0] = 1;
        //�����������
        while (!q.empty())
        {
            int s = q.front().s;
            int n = q.front().n;
            int m = q.front().m;
            int t = q.front().t;
            q.pop();
            if (s == S / 2 && n == S / 2 && m == 0)
            {
                res = t;
                break;
            }
            //ģ�⵹ˮ����
            //s -> n
            if (s != 0 && n != N)
            {
                int ss,nn;
                if (s <= N - n)
                {
                    ss = 0;
                    nn = n + s;
                }
                else
                {
                    ss = s - (N - n);
                    nn = N;
                }
                if (!book[ss][nn])
                {
                    book[ss][nn] = 1;
                    q.push(node(ss,nn,m,t + 1));
                }
            }
            //s -> m
            if (s != 0 && m != M)
            {
                int ss,mm;
                if (s <= M - m)
                {
                    ss = 0;
                    mm = m + s;
                }
                else
                {
                    ss = s - (M - m);
                    mm = M;
                }
                if (!book[ss][n])
                {
                    book[ss][n] = 1;
                    q.push(node(ss,n,mm,t + 1));
                }
            }
            //n -> s
            if (n != 0 && s != S)
            {
                int nn,ss;
                nn = 0;
                ss = s + n;
                if (!book[ss][nn])
                {
                    book[ss][nn] = 1;
                    q.push(node(ss,nn,m,t + 1));
                }
            }
            //n -> m
            if (n != 0 && m != M)
            {
                int nn,mm;
                if (n <= M - m)
                {
                    nn = 0;
                    mm = m + n;
                }
                else
                {
                    nn = n - (M - m);
                    mm = M;
                }
                if (!book[s][nn])
                {
                    book[s][nn] = 1;
                    q.push(node(s,nn,mm,t + 1));
                }
            }
            //m -> s
            if (m != 0 && s != S)
            {
                int mm,ss;
                mm = 0;
                ss = s + m;
                if (!book[ss][n])
                {
                    book[ss][n] = 1;
                    q.push(node(ss,n,mm,t + 1));
                }
            }
            //m -> n
            if (m != 0 && n != N)
            {
                int mm,nn;
                if (m <= N - n)
                {
                    mm = 0;
                    nn = n + m;
                }
                else
                {
                    mm = m - (N - n);
                    nn = N;
                }
                if (!book[s][nn])
                {
                    book[s][nn] = 1;
                    q.push(node(s,nn,mm,t + 1));
                }
            }
        }
        if (res == 0)
            printf("NO\n");
        else
            printf("%d\n",res);

    }
    return 0;
}
