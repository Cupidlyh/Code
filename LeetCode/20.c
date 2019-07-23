#include <stdio.h>
#include <stdlib.h>

bool isValid(char * s){
    int len=strlen(s),i,pop=0;//len为字符串的长度，pop是栈的指针
    if(len%2!=0)//长度是奇数时是错误的
        return false;
    if(len==0)//长度是0时是正确的
        return true;
    char str[10000];//栈
    memset(str,0,sizeof(str));//初始化数组
    for(i=0;i<len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){//如果是这三种就进栈
            str[pop++]=s[i];
        }
        else{
            if(pop>=1)//当栈中存入了的时候才将指针减一
            pop=pop-1;
            //括号匹配
            if((s[i]==']'&&str[pop]=='[')||(s[i]=='}'&&str[pop]=='{')||(s[i]==')'&&str[pop]=='(')){
            //匹配正确就将栈顶元素取出，因为上面有一步pop=pop-1，所以此时这里不用进行额外的操作
            }
            else
                return false;//匹配不上就是错误
        }
    }
    if(pop==0)
        return true;//最后栈中无元素时，才是正确的
    return false;
}
