#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int gcd(int n,int m)//շת����������Լ��
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
		g = gcd(g,arr[i]);//����n���������Լ�� 
	if(g != 1)//���Լ������1 
		cout<<"INF"<<endl;//˵�������޸��ղ����� 
	else {
		map[0] = 1;//���Ϊ1������Դճ��� 
		for(i = 0; i < n; i++) {
			for(j = 0; j + arr[i] < 10005; j++) {
				if(map[j] == 1)//�����ǰ���������Դճ��� 
					map[j + arr[i]] = 1;//��ô�ټ���ÿ��������İ�����Ҳ���Դճ��� 
			}
		}
		int num = 0;
		for(i = 0; i < 10000; i++)//ͳ�ƴղ������ĸ��������100��������ÿ�����100�����ӣ� 
			if(map[i] == 0)
				num++;
		cout<<num<<endl;
	}	
	return 0;
}
