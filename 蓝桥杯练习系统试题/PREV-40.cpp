#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
	ll arr[100005] = {0};//�洢��Ŀ�������� 
	ll sum[100005] = {0};//�洢ǰi��Ԫ�صĺͶ�k�����Ľ�� 
	ll cnt[100005] = {0};//��¼��ͬ�����ĸ��� 
	ll n,k,res = 0;
	cin>>n>>k;
	//����ͳ��ǰ׺��sum[i] ��ʾA1+A2+��+Ai. 
	//��������һ������[l,r]�ĺ;���sum[r]-sum[l-1].
	//���Ҫ��֤��������ΪK�������ǣ�(sum[r]-sum[l-1])%k == 0.���κ���ǣ�sum[r]%k==sum[l-1]%k
	for(int i = 1; i <= n; i++) {
		cin>>arr[i];
		sum[i] = (sum[i - 1] + arr[i]) % k;
		res = res + cnt[sum[i]];
		cnt[sum[i]]++;
	}
	cout<<res + cnt[0]<<endl;//�����Ҫ��������Ϊ0��������Լ��������һ�����䣩 
	return 0;
}
