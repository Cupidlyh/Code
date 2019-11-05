#include <stdio.h>
#include <stdlib.h>

char * minRemoveToMakeValid(char * s){//用栈来求解
    char *res = (char *)malloc(sizeof(char) * 100000);//结果数组

    //sign是标记数组，temp用来记录存进栈中的原数组的下标
    int sign[100000] = {0},temp[100000] = {0},head = 0,tail = strlen(s) - 1,i,j = 0;
    char stack[100000] = {'0'};//栈
    for(i = head; i <= tail; i++) {//遍历整个s数组
        if(s[i] == '(') {//当遍历到左括号时
            stack[j] = '(';//存进栈中
            temp[j] = i;//记录下在s中的下标
            sign[i] = 1;//标记
            j = j + 1;//栈的指针加1
        }
        if(s[i] == ')') {//当遍历到右括号时
            if(j > 0 && stack[j - 1] == '(') {//如果栈顶元素是左括号
                sign[temp[j - 1]] = 0;//清空标记
                j = j - 1;//栈的指针减一
            }
            else//如果栈顶元素不是左括号
                sign[i] = 1;//标记此位置s中的元素
        }
    }
    j = 0;
    for(i = 0; i < strlen(s); i++)//将最后的结果存进res数组中
        if(sign[i] == 0)//没被标记的存进结果数组
            res[j++] = s[i];
    res[j] = '\0';
    return res;
}
