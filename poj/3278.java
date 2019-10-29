package poj3278;

import java.util.*;//包含java.util包中所有的类

public class Main {//用广度优先搜索来做
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {//输入多组数据
			int map[] = new int[100001];//标记数组
			Queue<Integer> queue = new LinkedList<Integer>();//队列
			int n,k,num = 0;
			n = in.nextInt();
			k = in.nextInt();
			queue.add(n);//压入队列
			map[n] = 1;
			queue.add(-1);//-1是用来将每一步可以到达的点隔开
			while(!queue.isEmpty()) {
				int temp = queue.poll();//从队列弹出
				if(temp == -1) {
					num++;//步数加1
					queue.add(-1);
					continue;
				}
				else {
					if(temp == k)//等于k时说明找到了
						break;
					//存入当前点所有可能走过的点并进行去重
					if(temp - 1 >= 0 && map[temp - 1] == 0) {
						queue.add(temp - 1);
						map[temp - 1] = 1;
					}
					if(temp + 1 <= k && map[temp + 1] == 0) {
						queue.add(temp + 1);
						map[temp + 1] = 1;
					}
					if(temp * 2 <= 100000 && map[temp * 2] == 0) {
						queue.add(temp * 2);
						map[temp * 2] = 1;
					}
				}
			}
			System.out.println(num);
		}
	}
}
