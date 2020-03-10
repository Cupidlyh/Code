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
	int left = 0,right = 0;//有病的蚂蚁初始朝左或者朝右 
	for(i = 1; i < n; i++) {
		if(arr[i] > 0 && abs(arr[i]) < abs(arr[0]))//初始有病蚂蚁朝左走的情况（小于它并且向右走的都会得病） 
			left++;
		if(arr[i] < 0 && abs(arr[i]) > abs(arr[0]))//初始有病蚂蚁朝右走的情况（大于它并且向左走的都会得病）  
			right++;
	}
	if((arr[0] < 0 && left == 0) || (arr[i] > 0 && right == 0))//不会有其他蚂蚁染病的情况 
		cout<<1<<endl;
	else
		cout<<left + right + 1<<endl; 
	return 0;
}
