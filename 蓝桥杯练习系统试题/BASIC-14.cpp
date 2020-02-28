#include <iostream>
using namespace std;

int main() {
	int t,temp;
	cin>>t;
	cout<<t / 3600 <<":";
	temp = t % 3600;
	cout<<temp / 60 <<":";
	temp = temp % 60;
	cout<<temp<<endl;
	return 0;
}
