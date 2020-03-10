#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int arr[55] = {0};//存储蚂蚁初始位置信息 
	int n,i;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>arr[i];
	int left = 0,right = 0;
	for(i = 1; i < n; i++) {
		if(arr[i] > 0 && abs(arr[i]) < abs(arr[0]))//找到该蚂蚁左边且向右走的 
			right++;
		if(arr[i] < 0 && abs(arr[i]) > abs(arr[0]))//找到该蚂蚁右边且向左走的  
			left++;
	}
	if((arr[0] < 0 && right == 0) || (arr[i] > 0 && left == 0))//不会有其他蚂蚁染病的情况 
		cout<<1<<endl;
	else
		cout<<left + right + 1<<endl; 
	return 0;
}
