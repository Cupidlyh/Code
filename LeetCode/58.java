package leetcode;

public class Solution {
	public int lengthOfLastWord(String s) {
        if(s.length()==0) {//�������ַ�����Ϊ0ʱ
            return 0;
        }
        int len=s.length()-1,i,num=0;
        while(len>0&&s.charAt(len)==' ') {//���ַ���β���Ŀո�����
            len=len-1;
        }
        if(len==-1) {//����ַ���ȫΪ�ո�
            return 0;
        }
        for(i=len;i>=0;i--) {//ֱ�������һ�����ʵĳ���
            if(s.charAt(i)==' ')//��������ո�˵�����һ�����ʽ�����
                break;
            else
                num++;//num�Ǽ�¼���һ�����ʵĳ���
        }
        return num;
    }
}
