#include <stdio.h>
#include <stdlib.h>

int evalRPN(char ** tokens, int tokensSize){
    long long int arr[10000] = {0};//存放数字的栈
    int top = 0;//栈的指针
    for(int i=0;i<tokensSize;i++) {//遍历题目所给的二维数组
        if(strlen(tokens[i]) == 1) {//当前行长度为一时
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9')//如果是一位数字就存进栈中
                arr[top++] = tokens[i][0] - '0';
            else {//长度只有一位不是一位数字就是运算符
                switch(tokens[i][0])//判断是哪个运算符
                {
                    case '+':
                        arr[top-2] = arr[top-2] + arr[top-1];
                        top = top - 1;
                        break;
                    case '-':
                        arr[top-2] = arr[top-2] - arr[top-1];
                        top = top - 1;
                        break;
                    case '*':
                        arr[top-2] = arr[top-2] * arr[top-1];
                        top = top - 1;
                        break;
                    case '/':
                        arr[top-2] = arr[top-2] / arr[top-1];
                        top = top - 1;
                        break;
                }
            }
        }
        else {//当前行长度大于一时
            int sum = 0,num = 0;
            if(tokens[i][0] != '-') {//不是负数的情况
                for(int j=strlen(tokens[i])-1;j>=0;j--) {
                    sum = sum + (int)pow(10,num++) * (tokens[i][j] - '0');//将字符的数字计算成整型的数字
                }
                arr[top++] = sum;
            }
            else {//是负数的情况
                for(int j=strlen(tokens[i])-1;j>0;j--) {
                    sum = sum + (int)pow(10,num++) * (tokens[i][j] - '0');
                }
                arr[top++] = -sum;
            }
        }
    }
    return arr[0];
}
