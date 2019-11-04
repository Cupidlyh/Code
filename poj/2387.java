package poj2387;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {//多次输入
			int t,n,i,j,row,col,dis;
			t = in.nextInt();
			n = in.nextInt();
			long [][] map = new long[n + 1][n + 1];//由题中数据构建有向图
			long[] vis = new long[n + 1];//记录是否已经确定了最短路径
			long[] dist = new long[n + 1];//记录从源点到终点的最短路径长度
			for(i = 0; i < n + 1; i++) 
				for(j = 0; j < n + 1; j++) 
					map[i][j] = Integer.MAX_VALUE;//初始化
			for(i = 0;i < n + 1; i++)
				dist[i] = Integer.MAX_VALUE;//初始化
			for(i = 0; i < t; i++) {
				row = in.nextInt();
				col = in.nextInt();
				dis = in.nextInt();
				if(dis < map[row][col]) {//输入的数据存储较小的那个  
					map[row][col] = dis;
					map[col][row] = dis;
				}
			}
			Main dij = new Main();
			dij.dijastra(map, vis, dist, n);
			System.out.println(dist[n]);//输出结果
		}
	}
	
	public void dijastra(long[][] map,long[] vis,long[] dist,int n) {//迪杰斯特拉算法
		int v = 0;
		long min;
		for(int i = 1; i <= n; i++) {//初始化
			dist[i] = map[1][i];//将起点到各个终点的最短路径长度初始化为弧上的权值
		}
		vis[1] = 1;
		for(int j = 1; j <= n; j++) {//初始化结束，开始循环，每次求得起点到某个顶点v的最短路径，将v加入到vis中
			min = Integer.MAX_VALUE;
			for(int k = 1; k <= n; k++) {
				if(vis[k] == 0 && dist[k] < min) {//选择一条当前的最短路径，终点为v
					v = k;
					min = dist[k];
				}
			}
			vis[v] = 1;//将v加入vis中
			for(int w = 1; w <= n; w++) {//更新从起点出发所有顶点的最短路径长度
				if(vis[w] == 0 && (dist[v] + map[v][w] < dist[w])) {
					dist[w] = dist[v] + map[v][w];
				}
			}
		}
		return ;
	}
}
