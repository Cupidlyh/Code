package poj1797;

import java.util.*;//包含java.util包中所有的类

public class Main {
	public void dijastra(int[][] map, int[] vis, int[] dist, int n) {//迪杰斯特拉算法
		int v = 0, max;
		for (int i = 1; i <= n; i++) {//初始化
			vis[i] = 0;//标记数组初始化
			dist[i] = map[1][i];
		}
		dist[1] = 0;
		vis[1] = 0;
		for (int j = 1; j <= n; j++) { 
			max = Integer.MIN_VALUE;
			for (int k = 1; k <= n; k++) {
				if (vis[k] == 0 && dist[k] > max) {//选择一条当前的最长路径，终点为v 
					v = k;
					max = dist[k];
				}
			}
			vis[v] = 1;//将v加入vis中
			for (int w = 1; w <= n; w++) {
				if (vis[w] == 0 && Math.min(dist[v], map[v][w]) > dist[w]) {//因为题意找所有路径中最小承载量中的最大承载量，所以条件是这个
					dist[w] = Math.min(dist[v], map[v][w]);
				}
			}
		}
		return;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[][] map = new int[1010][1010];//存地图
		int[] vis = new int[1010];//标记点是否被走过
		int[] dist = new int[1010];//表示从1到n的所有路径中的最大承载量
		while (in.hasNext()) {
			int z, m, n, k;
			z = in.nextInt();
			for (k = 1; k <= z; k++) {
				n = in.nextInt();
				m = in.nextInt();
				int i, j, p, q, temp;
				for(i = 0; i <= n; i++)
					for(j = 0; j <= n; j++)
						map[i][j] = 0;//地图初始化
				for (i = 0; i < m; i++) {
					p = in.nextInt();
					q = in.nextInt();
					temp = in.nextInt();
					map[p][q] = temp;
					map[q][p] = temp;
				}
				Main dij = new Main();
				dij.dijastra(map, vis, dist, n);
				System.out.println("Scenario #" + k + ":");
				System.out.println(dist[n] + "\n");
			}
		}
	}

}
