#include <iostream>
using namespace std;

bool is_seven(int a) {//�ж������Ƿ����7������7�ı��� 
	if(a % 7 == 0)
		return true;
	while(a > 0) {
		if(a % 10 == 7)
			return true;
		a = a / 10;
	}
	return false;
}

int main() {
	int n,sum;
	cin>>n;
	sum = 0;//��ǰ�������������� 
	int a1 = 0,b1 = 0,c1 = 0,d1 = 0,a = 0,b = 0,c = 0,d = 0;//a,b,c,d������ұ������������֣�a1,b1,c1,d1��¼�����Ĵ��� 
	while(sum < n) {
		a = d + 1;
		if(is_seven(a))
			a1++;
		else
			sum++;
		if(sum == n)
			break;
		b = a + 1;
		if(is_seven(b))
			b1++;
		else
			sum++;
		if(sum == n)
			break;
		c = b + 1;
		if(is_seven(c))
			c1++;
		else
			sum++;
		if(sum == n)
			break;
		d = c + 1;
		if(is_seven(d))
			d1++;
		else
			sum++;
	}
	cout<<a1<<endl<<b1<<endl<<c1<<endl<<d1<<endl;
	return 0;
}
