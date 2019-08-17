#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int max=0,len=strlen(s),i,num=0,j;
    int arr[150]={0};//标记数组，标记字符是否出现过
    for(j=0;j<len;j++){//每个字符作为子串的开头依次进行尝试
        for(i=j;i<len;i++){
            if(arr[s[i]-' ']==0){//如果字符没出现过
                arr[s[i]-' ']=1;//将此字符进行标记
                num++;//长度加1
            }
            else{
                memset(arr,0,sizeof(arr));//数组置为零
                break;
            }
        }
        max=max>num?max:num;//取大的值
        num=0;//重新计数
    }
    return max;
}
