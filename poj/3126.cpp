#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int prime[10005];//素数表
int Count[10005];//记录到当前素数的费用
int vis[10005];//标记素数是否已经走过

void Init()//对素数打表
{
    int i,j;
    for(i = 1000; i <= 10005; i++)
    {
        for(j = 2; j < i; j++)
            if(i%j == 0)
            {
                prime[i] = 0;//不是素数置0
                break;
            }
        if(j == i)
            prime[i]=1;//是素数置1
    }

}

int dfs(int st,int last)
{
    queue<int>q;//初始化一个队列
    memset(vis,0,sizeof(vis));//数组初始化
    memset(Count,0,sizeof(Count));//数组初始化
    int t[4] = {0},i,j,cur,temp,ntemp;
    q.push(st);
    vis[st] = 1;
    while(!q.empty())
    {
        cur = q.front();//cur记录队头元素
        if(cur == last)//找到最后的数字
            return Count[cur];
        q.pop();
        t[0]=cur/1000;//将四位数cur拆开存储
        t[1]=cur%1000/100;
        t[2]=cur%100/10;
        t[3]=cur%10;
        for(i = 0; i < 4; i++)
        {
            temp = t[i];
            for(j = 0; j < 10; j++)//cur的每一位的去尝试所有可能的数字
            {
                if(j != temp)//当前数字和当前位的数字不同时
                {
                    t[i] = j;//取代当前位的数字
                    ntemp = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];//计算新的数字
                    if(vis[ntemp] == 0 && prime[ntemp] == 1)//数字没走过且是素数
                    {
                        vis[ntemp] = 1;//标记
                        q.push(ntemp);//入队
                        Count[ntemp] = Count[cur] + 1;//计算费用
                    }
                }
            }
            t[i] = temp;//位的数字复原
        }
    }
    return -1;
}

int main()
{
    memset(prime,0,sizeof(prime));//数组初始化
    Init();
    int n;
    cin>>n;
    while(n--)
    {
        int st,last;
        cin>>st>>last;
        int m = dfs(st,last);
        if(m == -1)
            cout<<"Impossible"<<endl;
        else
            cout<<m<<endl;

    }
    return 0;
}
