#include <stdio.h>
#include <stdlib.h>

bool isSubsequence(char * s, char * t){
    int s_len=strlen(s),t_len=strlen(t),i=0,j=0;
    if(s_len==0)//如果s长度为0，那他是任何字符串的子串
        return true;
    while(i<s_len&&j<t_len){//循环终止条件
        if(s[i]==t[j]){//判断s中的字母是否在t中出现
            if(i==s_len-1)//如果查验到了s字符串中的最后一个字母，直接跳出
                return true;
            i++;//继续检查s中的下一个字母
        }
        j++;
    }
    return false;
}


