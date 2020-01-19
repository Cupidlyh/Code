#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** printVertically(char* s, int* returnSize){
    int i,j,row = 0,col = 0;
    *returnSize = 0;
    char **arr = (char **)malloc(sizeof(char*)*205);//开辟二维数组
    for(i=0; i<205; i++) {
        arr[i]=(char *)malloc(sizeof(char)*205);
        for(j = 0;j < 205; j++)
            arr[i][j] = ' ';//数组初始化成空格
    }

    for(i = 0; i < strlen(s); i++) {//将所给的字符串中的单词竖着存储起来
        if(s[i] == ' ') {
            *returnSize = (*returnSize) > row ? (*returnSize) : row;
            col++;
            row = 0;
            continue;
        }
        else {
            arr[row++][col] = s[i];
        }
    }
    *returnSize = (*returnSize) > row ? (*returnSize) : row;
    for(i = 0; i < *returnSize; i++) {//因为尾部不允许有空格，并且尾部要有终止符，所以从二维数组每一行的尾部开始往前遍历
        for(j = col + 1; j >= 0; j--) {
            if(arr[i][j] == ' ')
                arr[i][j] = '\0';
            else
                break;
        }
    }
    return arr;
}


