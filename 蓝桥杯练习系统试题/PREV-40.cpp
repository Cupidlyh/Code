#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
	ll arr[100005] = {0};//存储题目给的数列 
	ll sum[100005] = {0};//存储前i个元素的和对k求余后的结果 
	ll cnt[100005] = {0};//记录不同余数的个数 
	ll n,k,res = 0;
	cin>>n>>k;
	//首先统计前缀和sum[i] 表示A1+A2+…+Ai. 
	//对于任意一段区间[l,r]的和就是sum[r]-sum[l-1].
	//如果要保证这个区间和为K倍数就是：(sum[r]-sum[l-1])%k == 0.变形后就是：sum[r]%k==sum[l-1]%k
	for(int i = 1; i <= n; i++) {
		cin>>arr[i];
		sum[i] = (sum[i - 1] + arr[i]) % k;
		res = res + cnt[sum[i]];
		cnt[sum[i]]++;
	}
	cout<<res + cnt[0]<<endl;//最后结果要加上余数为0的情况（自己本身就是一个区间） 
	return 0;
}
