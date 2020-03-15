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

//x��y��ʾ��ǰ���꣬num��ʾ��ǰ�õ��ı�������max��ʾ��ǰ���б����е�����ֵ 
//��dp[3][4][5][6]=7 ������map[3][4]��������5������ ��������ֵ��6 �����յ���7��·��
int dfs(int x,int y,int num,int max) {
	//�ж����״̬�Ƿ��Ѿ��߹�������߹���ֱ���ü�¼����ֵ���㣬��Ϊ�����п���Ϊ0���Զ���maxʱ����Сֵ-1 ��͵����޷���Ϊ�±�ʹ��  
	//ʵ����������������б����ֵû��0�������е�+1ȥ��Ҳ�ǿ��Ե�  ����Ļ����ȥ���϶�����Щ���ݲ��Եģ����ſ����ύ��һ�£�����������
	if(dp[x][y][num][max + 1] != -1)
		return dp[x][y][num][max + 1];
	long long t = 0;
	if(x == n - 1 && y == m - 1) {//������� 
		if(num == k || (num == k - 1 && map[x][y] > max))//�������½ǣ���1�����ܲ������½ǵ�Ҳ���ã���2��������½ǵıȵ�ǰ�Ĵ�������һ���������Ҳ��������·��
			t++;
		dp[x][y][num][max + 1] = t;
		return dp[x][y][num][max + 1]; 
	}
	if(x + 1 < n) {//������ 
		if(map[x][y] > max) {
			t += dfs(x + 1,y,num + 1,map[x][y]);
			t %= N;
		}
		t += dfs(x + 1,y,num,max);
		t %= N;
	}
	if(y + 1 < m) {//������ 
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
