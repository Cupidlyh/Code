package leetcode43;

public class Solution {
	public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0"))//当出现字符串为"0"的情况
            return "0";
        int num1len = num1.length(), num2len = num2.length(),i,j;
        int res[] = new int[num1len + num2len];//存放整型的字符串相乘后的结果
        for(i = num1len - 1; i >= 0; i--) {//从个位数开始逐位相乘
            for(j = num2len - 1; j >= 0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int p1 = i + j, p2 = i + j + 1;//乘积mul在res数组中的位置
                int sum = mul + res[p2];
                res[p1] = res[p1] + sum / 10;//将sum叠加到res数组中
                res[p2] = sum % 10;
            }
        }
        i = 0;
        while(i < num1len + num2len && res[i] == 0)//res数组前面可能有没用到的（未使用位）
            i++;
        String res1 = new String();//字符串
        StringBuilder builder = new StringBuilder();
        for(int z = i; z < num1len + num2len; z++)//将整型数组res中的值转换成字符串
            builder.append(res[z]);
        return builder.toString();//返回字符串
    }
}
