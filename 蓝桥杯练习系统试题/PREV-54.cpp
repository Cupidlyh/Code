#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int father[1000000];//��¼���ڵ�
int num[1000000];//���ڼ�¼�м������Ϻ�ÿ��������Ԫ�ص����� 

int Find(int x)//��ѯx�ĸ��ڵ㲢·��ѹ��
{
    if(father[x] != x)
        father[x] = Find(father[x]);
    return father[x];
}

void Union(int x,int y)//�ϲ�x��y�ļ���
{
    int rx,ry;
    rx=Find(x);
    ry=Find(y);
    if(rx!=ry)
        father[rx]=ry;
}

int main()
{
    int i;
    for(i = 0; i < 1000000; i++) {//��ʼ��
        father[i] = i;
        num[i] = 0;
    }
	int m,n,k,a,b;
	cin>>m>>n;
	cin>>k;
	for(i = 0; i < k; i++) {
		cin>>a>>b;
		Union(a,b);
	}
	for(i = 1; i <= m * n; i++)//���ڵ���ͬ����Ϊ��ͬһ������֮�� 
		num[Find(i)]++;
	int res = 0;
	for(i = 1; i <= m * n; i++)
		if(num[i] > 0)//�ҳ����ϵĸ��� 
			res++;
	cout<<res<<endl;
    return 0;
}
