package poj2387;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {//�������
			int t,n,i,j,row,col,dis;
			t = in.nextInt();
			n = in.nextInt();
			long [][] map = new long[n + 1][n + 1];//���������ݹ�������ͼ
			long[] vis = new long[n + 1];//��¼�Ƿ��Ѿ�ȷ�������·��
			long[] dist = new long[n + 1];//��¼��Դ�㵽�յ�����·������
			for(i = 0; i < n + 1; i++) 
				for(j = 0; j < n + 1; j++) 
					map[i][j] = Integer.MAX_VALUE;//��ʼ��
			for(i = 0;i < n + 1; i++)
				dist[i] = Integer.MAX_VALUE;//��ʼ��
			for(i = 0; i < t; i++) {
				row = in.nextInt();
				col = in.nextInt();
				dis = in.nextInt();
				if(dis < map[row][col]) {//��������ݴ洢��С���Ǹ�  
					map[row][col] = dis;
					map[col][row] = dis;
				}
			}
			Main dij = new Main();
			dij.dijastra(map, vis, dist, n);
			System.out.println(dist[n]);//������
		}
	}
	
	public void dijastra(long[][] map,long[] vis,long[] dist,int n) {//�Ͻ�˹�����㷨
		int v = 0;
		long min;
		for(int i = 1; i <= n; i++) {//��ʼ��
			dist[i] = map[1][i];//����㵽�����յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ
		}
		vis[1] = 1;
		for(int j = 1; j <= n; j++) {//��ʼ����������ʼѭ����ÿ�������㵽ĳ������v�����·������v���뵽vis��
			min = Integer.MAX_VALUE;
			for(int k = 1; k <= n; k++) {
				if(vis[k] == 0 && dist[k] < min) {//ѡ��һ����ǰ�����·�����յ�Ϊv
					v = k;
					min = dist[k];
				}
			}
			vis[v] = 1;//��v����vis��
			for(int w = 1; w <= n; w++) {//���´����������ж�������·������
				if(vis[w] == 0 && (dist[v] + map[v][w] < dist[w])) {
					dist[w] = dist[v] + map[v][w];
				}
			}
		}
		return ;
	}
}
