#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

int N;//����Ԫ�ظ���
ll a[100005];//ԭ����
ll c[100005];
ll c1[100005];

int lowbit(int x)
{
    return x&(-x);
}

ll getsum(int i)//��ǰ׺�ͣ���a[1]��a[i]�ĺͣ�
{
    ll res = 0;
    int x = i;
    while(i > 0)
    {
        res += x * c[i] - c1[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,ll k)//��iλ�ü���k���˺���ֻ������״�����ֵ����Ҫ����ԭ�����ֵ��Ҫ����������ʵ�֣�
{
    int x = i;//��Ϊx���䣬���Ե��ȱ���iֵ
    while(i <= N)
    {
        c[i] += k;
        c1[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int main()
{
    int Q,i;
    scanf("%d %d",&N,&Q);
    for(i = 1; i <= N; i++)
    {
        scanf("%I64d",&a[i]);
        updata(i,a[i] - a[i - 1]);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
    }
    char ch;
    int x,y,z;
    while(Q--)
    {
        getchar();
        scanf("%c",&ch);
        if(ch == 'Q')
        {
            scanf("%d %d",&x,&y);
            printf("%I64d\n",getsum(y) - getsum(x - 1));//��[x,y]�����

        }
        if(ch == 'C')
        {
            scanf("%d %d %d",&x,&y,&z);
            //[x,y]�����ڼ���z
            updata(x,z);//a[x] - a[x-1]����z
            updata(y + 1,-z);//a[y+1] - a[y]����z
        }
    }
    return 0;
}
