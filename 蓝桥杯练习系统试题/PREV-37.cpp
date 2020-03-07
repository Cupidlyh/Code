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
	int num;//记录巧克力被分成的块数 
	for(i = 1; i <= 100000; i++) {//每块巧克力分成的大小的边界是1到100000 
		num = 0; 
		for(j = 1; j <= n; j++) {//一共n块巧克力 
			num += (int)(H[j] / i) * (int)(W[j] / i);//计算每块巧克力如果被分成边长为i的巧克力所分成的块数并加进去 
			if(num >= k)//如果当前的块数大于小朋友数就跳出 
				break;
		}
		if(num < k)//如果块数小于了小朋友数就找到了答案，因为每块巧克力分成当前i的大小的巧克力不够小朋友分，那么分成更大边长的一定也不够分 
			break;
	}
	cout<<i - 1<<endl;//输出结果 
	return 0;
}
