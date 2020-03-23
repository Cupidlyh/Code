#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int a[100005],N,b[1000005];//a记录小朋友身高，b记录小朋友交换次数 
int C1[1000005],C2[1000005];//两个树状数组（通过对小朋友身高计数来建立树状数组，C1是从头到尾计数，C2为从尾到头计数） 
long long total[100005];//交换n次的总共不开心值 

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i,int *c)//求a[1]到a[i]的和(包含a[i])
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k,int *c)//在i位置加上k（此函数只更改树状数组的值，若要更改原数组的值需要在主函数中实现）
{
    while(i <= 1000005)//小朋友最高为1000000，所以小于1000005 
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main() {
	scanf("%d",&N);
	int i;
	for(i = 0; i < N; i++) {//从头到尾计数（C1） 
		scanf("%d",&a[i]);
		updata(a[i] + 1,1,C1);//因为小朋友身高值可以为0，而树状数组下标不能用0，所以要都加1 
		b[i] = i - getsum(a[i],C1);//计算在当前数之前且比它大的元素个数 
		b[i] = b[i] - (getsum(a[i] + 1,C1) - getsum(a[i],C1) - 1);//去重（身高相等的情况） 
	}
	for(i = N - 1; i >= 0; i--) {//从尾到头计数（C2） 
		updata(a[i] + 1,1,C2);
		b[i] = b[i] + getsum(a[i],C2);//计算在当前数之后且比它小的元素个数 
	}
	for(i = 1; i <= N; i++) {//计算交换n次的总共不开心值 
		total[i] = total[i - 1] + i;
	}
	long long ans = 0;
	for(i = 0; i < N; i++) {//计算结果 
		ans += total[b[i]];
	}
	printf("%I64d\n",ans);
	return 0;
}
