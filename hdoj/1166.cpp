#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int a[50005],c[50005],N;//��Ӧԭ�������״����

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//��a[1]��a[i]�ĺ�
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//��iλ�ü���k��ԭʼ�������״�����ֵ������ģ�
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
            updata(i,temp);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
        }
        string str;
        int j,k;
        while(cin>>str && str[0] != 'E')
        {
            cin>>j>>k;
            if(str[0] == 'A')
                updata(j,k);
            else if(str[0] == 'S')
                updata(j,-k);//��ȥ��������Ϊ�����෴��
            else if(str[0] == 'Q')
                cout<<getsum(k) - getsum(j - 1)<<endl;//x-y�����Ҳ�͵���1-y����ͼ�ȥ1-(x-1)�����
        }
    }
    return 0;
}
