#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int n,k,H[100005],W[100005];

bool judge(int m) {
	int num = 0;//��¼�ɿ������ֳɵĿ��� 
	for(int j = 1; j <= n; j++) {//һ��n����ɿ��� 
		num += (int)(H[j] / m) * (int)(W[j] / m);//����ÿ���ɿ���������ֳɱ߳�Ϊm���ɿ������ֳɵĿ������ӽ�ȥ 
		if(num >= k)//�����ǰ�Ŀ�������С�������ͷ����� 
			return true;
	}
	return false;
}
int main() {
	cin>>n>>k;
	int i;
	for(i = 1; i <= n; i++) 
		cin>>H[i]>>W[i]; 
	int left = 1,right = 100001,mid;//���ֵ����ұ߽���м�ֵ��Ĭ����߽��ǿ��Էֵ��ģ��ұ߽����޷��ֵ��ı߳��� 
	while(left < right - 1) {
		mid = left + (right - left) / 2;//�м�ֵ 
		if(judge(mid))//mid���Էֵ� 
			left = mid;//����߽� 
		else//mid�ֲ��� 
			right = mid;//���ұ߽� 
	}
	cout<<left<<endl;//�����߽� 
	return 0;
}

