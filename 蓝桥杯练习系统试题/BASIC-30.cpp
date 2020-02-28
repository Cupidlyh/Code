#include <iostream>
using namespace std;

int main() {
	int n,i,j,temp;
	cin>>n;
	int arr[3000] = {0};//存储数字 
	arr[0] = 1;
	int bit = 1;//数字的位数 
	int carry;//进位 
	for(i = 1; i <= n; i++) {
		carry = 0; 
		for(j = 0; j < bit; j++) {
			temp = arr[j] * i + carry;
			carry = 0;
			if(temp < 10) {
				arr[j] = temp;
			}
			else {
				arr[j] = temp % 10;
				carry = temp / 10;
			}
		}
		while(carry > 0) {
			arr[bit++] = carry % 10;
			carry = carry / 10;
		}
	}
	for(i = bit - 1; i >= 0; i--)//输出数字 
		cout<<arr[i];
	cout<<endl;
	return 0;
}
