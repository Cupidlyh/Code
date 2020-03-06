#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int gcd(int n,int m)//辗转相除法求最大公约数
{
    int temp;
    while(m > 0)
    {
        temp = n % m;
        n = m;
        m = temp;
    }
    return n;
}

int main() {
	int arr[105] = {0},map[10005] = {0},n,i,j;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>arr[i];
	int g = gcd(arr[0],arr[1]);
	for(i = 2; i < n; i++)
		g = gcd(g,arr[i]);//求这n个数的最大公约数 
	if(g != 1)//最大公约数不是1 
		cout<<"INF"<<endl;//说明有无限个凑不出来 
	else {
		map[0] = 1;//标记为1代表可以凑出来 
		for(i = 0; i < n; i++) {
			for(j = 0; j + arr[i] < 10005; j++) {
				if(map[j] == 1)//如果当前包子数可以凑出来 
					map[j + arr[i]] = 1;//那么再加上每种蒸笼里的包子数也可以凑出来 
			}
		}
		int num = 0;
		for(i = 0; i < 10000; i++)//统计凑不出来的个数（最多100种蒸笼，每笼最多100个包子） 
			if(map[i] == 0)
				num++;
		cout<<num<<endl;
	}	
	return 0;
}
