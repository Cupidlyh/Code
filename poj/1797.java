package poj1797;

import java.util.*;//����java.util�������е���

public class Main {
	public void dijastra(int[][] map, int[] vis, int[] dist, int n) {//�Ͻ�˹�����㷨
		int v = 0, max;
		for (int i = 1; i <= n; i++) {//��ʼ��
			vis[i] = 0;//��������ʼ��
			dist[i] = map[1][i];
		}
		dist[1] = 0;
		vis[1] = 0;
		for (int j = 1; j <= n; j++) { 
			max = Integer.MIN_VALUE;
			for (int k = 1; k <= n; k++) {
				if (vis[k] == 0 && dist[k] > max) {//ѡ��һ����ǰ���·�����յ�Ϊv 
					v = k;
					max = dist[k];
				}
			}
			vis[v] = 1;//��v����vis��
			for (int w = 1; w <= n; w++) {
				if (vis[w] == 0 && Math.min(dist[v], map[v][w]) > dist[w]) {//��Ϊ����������·������С�������е������������������������
					dist[w] = Math.min(dist[v], map[v][w]);
				}
			}
		}
		return;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[][] map = new int[1010][1010];//���ͼ
		int[] vis = new int[1010];//��ǵ��Ƿ��߹�
		int[] dist = new int[1010];//��ʾ��1��n������·���е���������
		while (in.hasNext()) {
			int z, m, n, k;
			z = in.nextInt();
			for (k = 1; k <= z; k++) {
				n = in.nextInt();
				m = in.nextInt();
				int i, j, p, q, temp;
				for(i = 0; i <= n; i++)
					for(j = 0; j <= n; j++)
						map[i][j] = 0;//��ͼ��ʼ��
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
