#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int n,k,H[100005],W[100005];
int main() {
	cin>>n>>k;
	int i,j;
	for(i = 1; i <= n; i++) 
		cin>>H[i]>>W[i]; 
	int num;//��¼�ɿ������ֳɵĿ��� 
	for(i = 1; i <= 100000; i++) {//ÿ���ɿ����ֳɵĴ�С�ı߽���1��100000 
		num = 0; 
		for(j = 1; j <= n; j++) {//һ��n���ɿ��� 
			num += (int)(H[j] / i) * (int)(W[j] / i);//����ÿ���ɿ���������ֳɱ߳�Ϊi���ɿ������ֳɵĿ������ӽ�ȥ 
			if(num >= k)//�����ǰ�Ŀ�������С������������ 
				break;
		}
		if(num < k)//�������С����С���������ҵ��˴𰸣���Ϊÿ���ɿ����ֳɵ�ǰi�Ĵ�С���ɿ�������С���ѷ֣���ô�ֳɸ���߳���һ��Ҳ������ 
			break;
	}
	cout<<i - 1<<endl;//������ 
	return 0;
}
