#include <stdio.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle){//BF算法
    int h_len=strlen(haystack),n_len=strlen(needle),j=0,sign=-1,k;
    if(n_len==0)//短串长度为0时肯定是任何字符串的子串，所以返回0
        return 0;
    //就在for循环的判断条件这里做了优化，长串中后面的字符就不用每一个都重新开始比较，直接不比较
    //因为后面的长度都小于短串，肯定匹配不上
    for(k=0;k<=h_len-n_len;k++){
        if(haystack[k]==needle[j]){
                    //记录这个首次相等时k的值，如果匹配失败，k的值要还原
            sign=k;//匹配如果成功，直接返回这个记录的k值
            j++;
            k++;
            while(haystack[k]==needle[j]&&j<n_len&&k<h_len){//注意不能超出两个数组的长度
                j++;
                k++;
            }
            if(j>=n_len)//如果while循环结束j等于它的长度，就说明匹配成功了
                return sign;
            else{//当匹配失败时
                k=sign;//k恢复原来的值，因为for循环，k还要加一次，就达到了从长串下一个字母开始重新比较的目的
                sign=-1;
                j=0;//j变为0，以便下次判断
            }
        }
    }
    return sign;
}
