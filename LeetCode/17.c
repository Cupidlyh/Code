#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

iint dlen,row;//dlen是记录所给的数字字符数组的长度，row记录的是最后返回数组的行
//digits是题目所给的数组，arr是我们自己开辟的记录结果的数组，n是记录digits数组遍历的位置，col记录arr数组存储到的列数
void dfs(char *digits,char **arr,int n,int col) {
    if(n==dlen) {//当digits数组遍历结束时
        arr[row][col]='\0';
        row=row+1;//行数加一，开始下一行的存储
        int k;
        for(k=0;k<=dlen;k++)//此行先保存下上一行的结果，因为回溯借用了上一次的结果
            arr[row][k]=arr[row-1][k];
        return ;
    }

    if(digits[n]=='2') {//数字为2时，将所对应的字母依次存进arr数组中并进行递归调用
        arr[row][col]='a';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='b';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='c';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='3') {
        arr[row][col]='d';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='e';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='f';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='4') {
        arr[row][col]='g';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='h';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='i';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='5') {
        arr[row][col]='j';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='k';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='l';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='6') {
        arr[row][col]='m';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='n';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='o';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='7') {
        arr[row][col]='p';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='q';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='r';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='s';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='8') {
        arr[row][col]='t';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='u';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='v';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='9') {
        arr[row][col]='w';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='x';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='y';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='z';
        dfs(digits,arr,n+1,col+1);
    }
    return ;
}

char ** letterCombinations(char * digits, int* returnSize){
    int i;
    dlen=strlen(digits);
    row=0;
    char **arr =(char **)malloc(sizeof(char*)*20000);//开辟二维数组
    for(i=0; i<20000; i++)
        arr[i]=(char *)malloc(sizeof(char)*(dlen+1));
    if(dlen==0) {//当所给数组长度为0时
        *returnSize=0;
        return arr;
    }
    dfs(digits,arr,0,0);//递归调用
    *returnSize=row;
    return arr;
}
