#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int a[100005],N,b[1000005];//a��¼С������ߣ�b��¼С���ѽ������� 
int C1[1000005],C2[1000005];//������״���飨ͨ����С������߼�����������״���飬C1�Ǵ�ͷ��β������C2Ϊ��β��ͷ������ 
long long total[100005];//����n�ε��ܹ�������ֵ 

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i,int *c)//��a[1]��a[i]�ĺ�(����a[i])
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k,int *c)//��iλ�ü���k���˺���ֻ������״�����ֵ����Ҫ����ԭ�����ֵ��Ҫ����������ʵ�֣�
{
    while(i <= 1000005)//С�������Ϊ1000000������С��1000005 
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main() {
	scanf("%d",&N);
	int i;
	for(i = 0; i < N; i++) {//��ͷ��β������C1�� 
		scanf("%d",&a[i]);
		updata(a[i] + 1,1,C1);//��ΪС�������ֵ����Ϊ0������״�����±겻����0������Ҫ����1 
		b[i] = i - getsum(a[i],C1);//�����ڵ�ǰ��֮ǰ�ұ������Ԫ�ظ��� 
		b[i] = b[i] - (getsum(a[i] + 1,C1) - getsum(a[i],C1) - 1);//ȥ�أ������ȵ������ 
	}
	for(i = N - 1; i >= 0; i--) {//��β��ͷ������C2�� 
		updata(a[i] + 1,1,C2);
		b[i] = b[i] + getsum(a[i],C2);//�����ڵ�ǰ��֮���ұ���С��Ԫ�ظ��� 
	}
	for(i = 1; i <= N; i++) {//���㽻��n�ε��ܹ�������ֵ 
		total[i] = total[i - 1] + i;
	}
	long long ans = 0;
	for(i = 0; i < N; i++) {//������ 
		ans += total[b[i]];
	}
	printf("%I64d\n",ans);
	return 0;
}
