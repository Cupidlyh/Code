#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b)
{
     return(*(char *)a-*(char *)b);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    int book[strsSize],i,j;//book为标记数组
    char **strscpy = (char **)malloc(sizeof(char *) * strsSize);//将strs数组中的字符串赋给strscpy数组
    for(i = 0; i < strsSize; i++) {
        book[i] = 0;//标记数组置0
        strscpy[i] = (char *)malloc(sizeof(char) * strlen(strs[i]) + 1);
        strcpy(strscpy[i], strs[i]);
        qsort(strscpy[i],strlen(strscpy[i]),sizeof(strscpy[i][0]),cmp);//将每一行的字符串进行排序
    }
    char ***res = (char ***)malloc(sizeof(char **)*strsSize);//开辟三维数组记录结果
    int row = 0,col = 0;//row记录的是三维数组的层数，col记录三维数组每一层的行数
    for(i = 0; i < strsSize; i++) {//遍历整个二维的stscpy数组
        if(book[i] == 1)//如果当前行被标记就跳过
            continue;
        book[i] = 1;//标记当前行
        res[row] = (char **)malloc(sizeof(char*) * strsSize);
        res[row][col] = (char *)malloc(sizeof(char) * strlen(strs[i]) + 1);
        strcpy(res[row][col++],strs[i]);//将当前行的字符串赋给三维数组第row层第col行
        for(j = i + 1; j < strsSize; j++) {
            if(strcmp(strscpy[i],strscpy[j]) == 0) {//第i行的字符串和后面每一行的字符串进行比较，如果相同
                book[j] = 1;//进行标记
                res[row][col] = (char *)malloc(sizeof(char) * strlen(strs[j]) + 1);
                strcpy(res[row][col++],strs[j]);//存到三维数组第row层第col行
            }
        }
        (*returnColumnSizes)[row] = col;
        col = 0;//重新记录下一层的行数
        row++;//层数加1
    }
    *returnSize = row;
    return res;
}
