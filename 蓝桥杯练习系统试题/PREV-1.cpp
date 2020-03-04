#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int a,b,c,temp;
	cin>>a>>b>>c;
	if(c < a || c < b) {
		if(a > b) {
			temp = a;
			a = c;
			c = temp;
		}
		else {
			temp = b;
			b = c;
			c = temp;
		}
	}
	temp = c;//c是组员数最多的那一组的组员数 
	while(true) {
		if(temp % a == 0 && temp % b == 0)
			break;
		temp = temp + c;
	}
	cout<<temp<<endl;
	return 0;
}
