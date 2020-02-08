#include <iostream>
#include <cstdio>
using namespace std;

bool is_rus(int x[1005],int y[1005],int n,int x1,int y1) {//判断点（x1，y1）是否可以建回收站 
	int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
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
		if(flag == 0)//如果此点的上下左右有一个不是杂物点那此点就不能建回收站 
			return false;
	}
	return true;
}

int num(int x[1005],int y[1005],int n,int x1,int y1) {//对可以建回收站的点进行评分 
	int coor[4][2] = {-1,1,1,1,-1,-1,1,-1};//左上右上左下右下 
	int i,tx,ty,j,m = 0;
	for(i = 0; i < 4; i++) {
		tx = x1 + coor[i][0];
		ty = y1 + coor[i][1];
		for(j = 1; j <= n; j++) {
			if(x[j] == tx && y[j] == ty) { 
				m++;//分数加一 
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
	for(i = 1; i <= n; i++) {//对所有的点进行遍历 
		if(is_rus(x,y,n,x[i],y[i]))
			res[num(x,y,n,x[i],y[i])]++;
	}
	for(i = 0; i < 5; i++) {//输出每个评分的回收站个数 
		printf("%d\n",res[i]);
	}
	return 0;
}
