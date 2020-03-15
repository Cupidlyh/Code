#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


#define N 1000000007
int n,m,k;
int map[55][55];
int dp[55][55][20][20];

//x，y表示当前坐标，num表示当前拿到的宝物数，max表示当前所有宝物中的最大价值 
//如dp[3][4][5][6]=7 即当在map[3][4]且身上有5件宝物 宝物的最大值是6 到达终点有7种路径
int dfs(int x,int y,int num,int max) {
	//判断这个状态是否已经走过，如果走过就直接用记录的数值计算，因为宝物有可能为0所以定义max时用最小值-1 这就导致无法作为下标使用  
	//实际上如果测试数据中宝物价值没有0，将所有的+1去掉也是可以的  这里的话如果去掉肯定是有些数据不对的，不信可以提交试一下，根本过不了
	if(dp[x][y][num][max + 1] != -1)
		return dp[x][y][num][max + 1];
	long long t = 0;
	if(x == n - 1 && y == m - 1) {//到达出口 
		if(num == k || (num == k - 1 && map[x][y] > max))//到达右下角，（1）可能不算右下角的也正好，（2）如果右下角的比当前的大，算上这一个如果正好也可以增加路径
			t++;
		dp[x][y][num][max + 1] = t;
		return dp[x][y][num][max + 1]; 
	}
	if(x + 1 < n) {//向下走 
		if(map[x][y] > max) {
			t += dfs(x + 1,y,num + 1,map[x][y]);
			t %= N;
		}
		t += dfs(x + 1,y,num,max);
		t %= N;
	}
	if(y + 1 < m) {//向右走 
		if(map[x][y] > max) {
			t += dfs(x,y + 1,num + 1,map[x][y]);
			t %= N;
		}
		t += dfs(x,y + 1,num,max);
		t %= N;
	}
	dp[x][y][num][max + 1] = t;
	return dp[x][y][num][max + 1]; 
}


int main() {
	cin>>n>>m>>k;
	int i,j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin>>map[i][j];
	memset(dp,-1,sizeof(dp));
	dfs(0,0,0,-1);
	cout<<dp[0][0][0][0]<<endl;
	return 0;
}
