package leetcode;

public class Solution {
	public int lengthOfLastWord(String s) {
        if(s.length()==0) {//当所传字符长度为0时
            return 0;
        }
        int len=s.length()-1,i,num=0;
        while(len>0&&s.charAt(len)==' ') {//将字符串尾部的空格跳过
            len=len-1;
        }
        if(len==-1) {//如果字符串全为空格
            return 0;
        }
        for(i=len;i>=0;i--) {//直接算最后一个单词的长度
            if(s.charAt(i)==' ')//如果遇见空格，说明最后一个单词结束了
                break;
            else
                num++;//num是记录最后一个单词的长度
        }
        return num;
    }
}
