#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int a[50005],c[50005],N;//对应原数组和树状数组

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//求a[1]到a[i]的和
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//在i位置加上k（原始数组和树状数组的值都会更改）
{
    a[i] += k;
    while(i <= N)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main()
{
    int T,num = 1;
    cin>>T;
    while(T--)
    {
        cout<<"Case "<<num++<<":"<<endl;
        int i,temp;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        cin>>N;
        for(i = 1; i <= N; i++)
        {
            cin>>temp;
            updata(i,temp);//输入初值的时候，也相当于更新了值
        }
        string str;
        int j,k;
        while(cin>>str && str[0] != 'E')
        {
            cin>>j>>k;
            if(str[0] == 'A')
                updata(j,k);
            else if(str[0] == 'S')
                updata(j,-k);//减去操作，即为加上相反数
            else if(str[0] == 'Q')
                cout<<getsum(k) - getsum(j - 1)<<endl;//x-y区间和也就等于1-y区间和减去1-(x-1)区间和
        }
    }
    return 0;
}
