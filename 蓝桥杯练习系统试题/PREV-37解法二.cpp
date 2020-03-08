#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int n,k,H[100005],W[100005];

bool judge(int m) {
	int num = 0;//记录巧克力被分成的块数 
	for(int j = 1; j <= n; j++) {//一共n大块巧克力 
		num += (int)(H[j] / m) * (int)(W[j] / m);//计算每块巧克力如果被分成边长为m的巧克力所分成的块数并加进去 
		if(num >= k)//如果当前的块数大于小朋友数就返回真 
			return true;
	}
	return false;
}
int main() {
	cin>>n>>k;
	int i;
	for(i = 1; i <= n; i++) 
		cin>>H[i]>>W[i]; 
	int left = 1,right = 100001,mid;//二分的左右边界和中间值（默认左边界是可以分到的，右边界是无法分到的边长） 
	while(left < right - 1) {
		mid = left + (right - left) / 2;//中间值 
		if(judge(mid))//mid可以分到 
			left = mid;//给左边界 
		else//mid分不到 
			right = mid;//给右边界 
	}
	cout<<left<<endl;//输出左边界 
	return 0;
}

