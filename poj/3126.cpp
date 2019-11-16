#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int prime[10005];//������
int Count[10005];//��¼����ǰ�����ķ���
int vis[10005];//��������Ƿ��Ѿ��߹�

void Init()//���������
{
    int i,j;
    for(i = 1000; i <= 10005; i++)
    {
        for(j = 2; j < i; j++)
            if(i%j == 0)
            {
                prime[i] = 0;//����������0
                break;
            }
        if(j == i)
            prime[i]=1;//��������1
    }

}

int dfs(int st,int last)
{
    queue<int>q;//��ʼ��һ������
    memset(vis,0,sizeof(vis));//�����ʼ��
    memset(Count,0,sizeof(Count));//�����ʼ��
    int t[4] = {0},i,j,cur,temp,ntemp;
    q.push(st);
    vis[st] = 1;
    while(!q.empty())
    {
        cur = q.front();//cur��¼��ͷԪ��
        if(cur == last)//�ҵ���������
            return Count[cur];
        q.pop();
        t[0]=cur/1000;//����λ��cur�𿪴洢
        t[1]=cur%1000/100;
        t[2]=cur%100/10;
        t[3]=cur%10;
        for(i = 0; i < 4; i++)
        {
            temp = t[i];
            for(j = 0; j < 10; j++)//cur��ÿһλ��ȥ�������п��ܵ�����
            {
                if(j != temp)//��ǰ���ֺ͵�ǰλ�����ֲ�ͬʱ
                {
                    t[i] = j;//ȡ����ǰλ������
                    ntemp = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];//�����µ�����
                    if(vis[ntemp] == 0 && prime[ntemp] == 1)//����û�߹���������
                    {
                        vis[ntemp] = 1;//���
                        q.push(ntemp);//���
                        Count[ntemp] = Count[cur] + 1;//�������
                    }
                }
            }
            t[i] = temp;//λ�����ָ�ԭ
        }
    }
    return -1;
}

int main()
{
    memset(prime,0,sizeof(prime));//�����ʼ��
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
