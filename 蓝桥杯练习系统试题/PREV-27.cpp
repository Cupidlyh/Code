#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int arr[55] = {0};//�洢���ϳ�ʼλ����Ϣ 
	int n,i;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>arr[i];
	int left = 0,right = 0;
	for(i = 1; i < n; i++) {
		if(arr[i] > 0 && abs(arr[i]) < abs(arr[0]))//�ҵ�����������������ߵ� 
			right++;
		if(arr[i] < 0 && abs(arr[i]) > abs(arr[0]))//�ҵ��������ұ��������ߵ�  
			left++;
	}
	if((arr[0] < 0 && right == 0) || (arr[i] > 0 && left == 0))//��������������Ⱦ������� 
		cout<<1<<endl;
	else
		cout<<left + right + 1<<endl; 
	return 0;
}
