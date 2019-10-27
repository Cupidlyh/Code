package leetcode43;

public class Solution {
	public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0"))//�������ַ���Ϊ"0"�����
            return "0";
        int num1len = num1.length(), num2len = num2.length(),i,j;
        int res[] = new int[num1len + num2len];//������͵��ַ�����˺�Ľ��
        for(i = num1len - 1; i >= 0; i--) {//�Ӹ�λ����ʼ��λ���
            for(j = num2len - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int p1 = i + j, p2 = i + j + 1;//�˻�mul��res�����е�λ��
                int sum = mul + res[p2];
                res[p1] = res[p1] + sum / 10;//��sum���ӵ�res������
                res[p2] = sum % 10;
            }
        }
        i = 0;
        while(i < num1len + num2len && res[i] == 0)//res����ǰ�������û�õ��ģ�δʹ��λ��
            i++;
        String res1 = new String();//�ַ���
        StringBuilder builder = new StringBuilder();
        for(int z = i; z < num1len + num2len; z++)//����������res�е�ֵת�����ַ���
            builder.append(res[z]);
        return builder.toString();//�����ַ���
    }
}
