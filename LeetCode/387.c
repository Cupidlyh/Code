#include <stdio.h>
#include <stdlib.h>

int firstUniqChar(char * s){
        int first=-1,i,count[26]={};//数组初始化为零
        for(i=0;i<strlen(s);i++){//第一遍遍历数组
            count[s[i]-'a']=count[s[i]-'a']+1;//将字母出现的次数记录下来
        }
        for(i=0;i<strlen(s);i++)//第二遍遍历数组
            if(count[s[i]-'a']==1){//找到首个只出现一次的那个字母
                first=i;
                break;
            }
        return first;
}
