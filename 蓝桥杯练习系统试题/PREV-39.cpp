#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include<algorithm>
#include <cmath>
using namespace std;


struct node {
	int yyyy,mm,dd;
} p[10];
int cnt = 0;

int month[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};//�·ݵ����� 

bool judgeyear(int n) {//�ж��Ƿ�������
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return true;
    return false;
}

void check(int y,int m,int d) {
	if(y < 1960 || y > 2059)//��ݲ�����Ҫ�� 
		return ;
	if(m <= 0 || m > 12)//�·ݲ�����Ҫ�� 
		return ;
	if(judgeyear(y))//����2��29�죬ƽ��2��28�� 
		month[2] = 29;
	else
		month[2] = 28;
	if(d > month[m] || d <= 0)//����������Ҫ�� 
		return ;
	p[cnt].yyyy = y;
	p[cnt].mm = m;
	p[cnt++].dd = d;
	return ;	
}

bool cmp(node a,node b) {//�Ƚ��� �����ڴ�С�������� 
	if(a.yyyy != b.yyyy)
		return a.yyyy < b.yyyy;
	else if(a.mm != b.mm)
		return a.mm < b.mm;
	else if(a.dd != b.dd)
		return a.dd < b.dd;
}


int main() {
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	check(a + 1900,b,c);
	check(a + 2000,b,c);
	check(c + 1900,a,b);
	check(c + 2000,a,b);
	check(c + 1900,b,a);
	check(c + 2000,b,a);
	sort(p,p+cnt,cmp);//���� 
	printf("%d-%02d-%02d\n",p[0].yyyy,p[0].mm,p[0].dd);
	for(int i = 1; i < cnt; i++)
		if(p[i].yyyy == p[i - 1].yyyy && p[i].mm == p[i - 1].mm && p[i].dd == p[i - 1].dd)//ȥ�� 
			continue;
		else
			printf("%d-%02d-%02d\n",p[i].yyyy,p[i].mm,p[i].dd);
	return 0;
}
