#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return strcmp(*(char**)a, *(char**)b);
}

char ** removeSubfolders(char ** folder, int folderSize, int* returnSize){
    qsort((void*)folder, folderSize, sizeof(char *), cmp);//将二维数组按照字典序排序
    int i,j,k,row = 0;
    char **res = (char **)malloc(sizeof(char*) * folderSize);//开辟二维数组
    for(i = 0; i < folderSize; i++)
        res[i] = (char *)malloc(sizeof(char) * 105);

    for(i = 0; i < folderSize; i++) {
        for(j = i + 1; j < folderSize; j++) {//判断第i个后面是否有它的子文件夹
            for(k = 0; k < strlen(folder[i]); k++) {
                if(folder[i][k] != folder[j][k])
                    break;
            }
            if(k >= strlen(folder[i]) && folder[j][k] == '/')//满足条件说明是第i个的子文件夹
                continue;//判断下一个
            else {//否则
                strcpy(res[row],folder[i]);//存进结果数组中
                row++;
                i = j - 1;//下次i的子文件夹的寻找要从这个不满足的开始
                break;
            }
        }
        if(j >= folderSize) {//字符串全遍历完，都是第i个的子文件夹
            strcpy(res[row],folder[i]);//存进结果数组
            row++;
            break;
        }
    }
    *returnSize = row;//记录下二维数组的行数
    return res;
}
