#include <iostream>
#include <cstdio>
using namespace std;

bool is_rus(int x[1005],int y[1005],int n,int x1,int y1) {//�жϵ㣨x1��y1���Ƿ���Խ�����վ 
	int coor[4][2] = {0,1,0,-1,-1,0,1,0};//��������
	int i,tx,ty,j,flag;
	for(i = 0; i < 4; i++) {
		flag = 0;
		tx = x1 + coor[i][0];
		ty = y1 + coor[i][1];
		for(j = 1; j <= n; j++) {
			if(x[j] == tx && y[j] == ty) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)//����˵������������һ������������Ǵ˵�Ͳ��ܽ�����վ 
			return false;
	}
	return true;
}

int num(int x[1005],int y[1005],int n,int x1,int y1) {//�Կ��Խ�����վ�ĵ�������� 
	int coor[4][2] = {-1,1,1,1,-1,-1,1,-1};//���������������� 
	int i,tx,ty,j,m = 0;
	for(i = 0; i < 4; i++) {
		tx = x1 + coor[i][0];
		ty = y1 + coor[i][1];
		for(j = 1; j <= n; j++) {
			if(x[j] == tx && y[j] == ty) { 
				m++;//������һ 
				break;
			}
		}
	}
	return m;
}

int main() {
	int x[1005] = {0},y[1005] = {0},res[5] = {0};
	int n,i;
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		scanf("%d %d",&x[i],&y[i]);
	for(i = 1; i <= n; i++) {//�����еĵ���б��� 
		if(is_rus(x,y,n,x[i],y[i]))
			res[num(x,y,n,x[i],y[i])]++;
	}
	for(i = 0; i < 5; i++) {//���ÿ�����ֵĻ���վ���� 
		printf("%d\n",res[i]);
	}
	return 0;
}
