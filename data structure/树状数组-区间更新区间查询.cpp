#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int N;//����Ԫ�ظ���
int a[100005];//ԭ����
int c[100005];
int c1[100005];

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//��ǰ׺�ͣ���a[1]��a[i]�ĺͣ�
{
    int res = 0;
    int x = i;
    while(i > 0)
    {
        res += x * c[i] - c1[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//��iλ�ü���k���˺���ֻ������״�����ֵ����Ҫ����ԭ�����ֵ��Ҫ����������ʵ�֣�
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
    int i;
    scanf("%d",&N);
    for(i = 1; i <= N; i++)
    {
        scanf("%d",&a[i]);
        updata(i,a[i] - a[i - 1]);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
    }


    int x,y,z;


    scanf("%d %d",&x,&y);
    printf("%d\n",getsum(y) - getsum(x - 1));//��[x,y]�����




    scanf("%d %d %d",&x,&y,&z);
    //[x,y]�����ڼ���z
    updata(x,z);//a[x] - a[x-1]����z
    updata(y + 1,-z);//a[y+1] - a[y]����z

    return 0;
}
