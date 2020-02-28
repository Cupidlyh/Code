#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	char a[110] = {'0'},b[110] = {'0'};
	int i,j = 0,temp,aa[110] = {0},bb[110] = {0},cc[110] = {0};
	cin>>a>>b;
	for(i = strlen(a) - 1; i >= 0; i--)//将字符转成数字存储在数组中（个位在0的位置） 
		aa[j++] = a[i] - '0';
	j = 0;
	for(i = strlen(b) - 1; i >= 0; i--)
		bb[j++] = b[i] - '0';
	j = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	int carry = 0;//进位
	for(i = 0; i < j; i++) {
		temp = aa[i] + bb[i] + carry;
		carry = 0;
		if(temp < 10) {
			cc[i] = temp;
		}
		else {
			cc[i] = temp % 10;
			carry = temp / 10;
		}
	}
	while(carry > 0) {
		cc[j++] = carry % 10;
		carry = carry / 10; 
	}
	for(i = j - 1; i >= 0; i--)//输出数字 
		cout<<cc[i];
	cout<<endl;
	return 0;
}
