package poj1426;


import java.util.*;//����java.util�������е���

public class Main {//�����������������
	static int t;//ȫ�ֱ���
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {///�������
			int n;
			n = in.nextInt();
			if(n == 0)
				break;
			Main a = new Main();
			t = 0;//t�����ж��Ƿ��Ѿ��ҵ���һ����ȷ�Ľ�
			int step = 1;//step��¼����m��λ��
			a.dfs(n,1,step);//����dfs����
		}
		
	}
	
	public void dfs(int n,long m,int step) {
		if(t == 1 || step > 19)//java��long��������ֵ�λ��Ϊ19λ
			return ;
		if(m % n == 0) {//�ж�m�Ƿ�Ϊn��������
			System.out.println(m);
			t = 1;//�ҵ���ȷ�Ľ⣬t���Ϊ1
		}
		//�������е�ֻ��01��ʮ��������
		dfs(n,m * 10,step + 1);
		dfs(n,m * 10 + 1,step + 1);
	}
}

