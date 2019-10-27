package poj3278;

import java.util.*;//����java.util�������е���

public class Main {//�ù��������������
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()) {//�����������
			int map[] = new int[100001];//�������
			Queue<Integer> queue = new LinkedList<Integer>();//����
			int n,k,num = 0;
			n = in.nextInt();
			k = in.nextInt();
			queue.add(n);//ѹ�����
			map[n] = 1;
			queue.add(-1);//-1��������ÿһ�����Ե���ĵ����
			while(!queue.isEmpty()) {
				int temp = queue.poll();//�Ӷ��е���
				if(temp == -1) {
					num++;//������1
					queue.add(-1);
					continue;
				}
				else {
					if(temp == k)//����kʱ˵���ҵ���
						break;
					//���뵱ǰ�����п����߹��ĵ㲢����ȥ��
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
