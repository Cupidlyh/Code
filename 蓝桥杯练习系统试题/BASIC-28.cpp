#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int cmp(const void *a,const void *b) {
	const int p1 = *(const int*)a;
	const int p2 = *(const int*)b;
	if(p1 < p2)
		return -1;
	else if(p1 > p2)
		return 1;
	return 0; 
}//从小到大排序 

int main() {
	int i,n,arr[105] = {0},res = 0;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>arr[i];
	qsort(arr,n,sizeof(arr[0]),cmp);//排序
	for(i = 1; i < n; i++) {
		arr[i] = arr[i] + arr[i - 1];
		arr[i - 1] = 0;
		res = res + arr[i];//计算费用
		qsort(arr,n,sizeof(arr[0]),cmp);
	}
	cout<<res<<endl;
	return 0;
}
