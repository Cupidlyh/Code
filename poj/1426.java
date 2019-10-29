package poj1426;


import java.util.*;//包含java.util包中所有的类

public class Main {//用深度优先搜索来做
	static int t;//全局变量
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {///多次输入
			int n;
			n = in.nextInt();
			if(n == 0)
				break;
			Main a = new Main();
			t = 0;//t用来判断是否已经找到了一个正确的解
			int step = 1;//step记录数字m的位数
			a.dfs(n,1,step);//调用dfs函数
		}
		
	}
	
	public void dfs(int n,long m,int step) {
		if(t == 1 || step > 19)//java中long型最大数字的位数为19位
			return ;
		if(m % n == 0) {//判断m是否为n的整数倍
			System.out.println(m);
			t = 1;//找到正确的解，t标记为1
		}
		//尝试所有的只含01的十进制数字
		dfs(n,m * 10,step + 1);
		dfs(n,m * 10 + 1,step + 1);
	}
}

