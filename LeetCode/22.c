#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int col,row;
//left是左括号用了几个，right是右括号用了几个
void gen(int left,int right,int n,char **str) {
  if(left==n&&right==n) {//左右括号都用完时
    int i;
    str[row][col]='\0';//字符串结束标志
    row++;//继续在下一行存下一种情况
    for(i=0;i<2*n;i++)
      str[row][i]=str[row-1][i];//将这一种情况存到下一行中，因为递归回退算下一种情况是在上一种的基础上进行的
    return ;
  }
  if(left<n) {//左括号没用完时
    str[row][col++]='(';//左括号存入
    gen(left+1,right,n,str);//左括号加1，递归
    col=col-1;//当递归退出来时，进入下一次尝试，列数减1
  }
  if(left>right&&right<n) {//右括号没用完并且左括号个数大于
    str[row][col++]=')';//右括号存入
    gen(left,right+1,n,str);//右括号加1，递归
    col=col-1;//当递归退出来时，进入下一次尝试，列数减1
  }
}

char ** generateParenthesis(int n, int* returnSize){
  int i;
  char **str =(char **)malloc(sizeof(char*)*5000);//开辟一个二维数组，有5000行
    for(i=0; i<5000; i++)
        str[i]=(char *)malloc(sizeof(char)*5000);//每一行5000列
  col=0;//记录列
  row=0;//记录行
  gen(0,0,n,str);
  *returnSize=row;//返回行数
  return str;
}
