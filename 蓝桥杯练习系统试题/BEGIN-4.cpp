#include <iostream>
#include <cstring>
using namespace std;

int arr[1000005];

int main() {
	memset(arr,0,sizeof(arr));
	arr[1] = 1;
	arr[2] = 1;
	int i,n;
	for(i = 3; i < 1000000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	while(cin>>n)
		cout<<arr[n]<<endl;
	return 0;
}
