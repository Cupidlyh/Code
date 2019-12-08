#include <stdio.h>
#include <stdlib.h>



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    //vis_c用来标记col_c数组是否已经存满，col_c数组记录结果数组当前行可以存进元素的个数
    int i,row = 0,vis_c[505] = {0},col_c[505] = {0},temp,j;
    int **res = (int **)malloc(sizeof(int *) * 505);//记录结果的二维数组
    for(i = 0; i < 505; i++) {
        res[i] = (int *)malloc(sizeof(int) * 505);
    }

    int *col = (int *)malloc(sizeof(int) * 505);//记录每行元素个数的一维数组
    for(i = 0; i < 505; i++)
        col[i] = 0;

    col_c[row] = groupSizes[row];//记录当前行可以存进元素的个数
    res[row][col[row]++] = 0;//下标存进结果数组中
    if(col[row] == col_c[row]) {//如果已经存满
        vis_c[row] = 1;//标记
    }
    for(i = 1; i < groupSizesSize; i++) {//遍历题目中所给的数组
        temp = groupSizes[i];
        int flag = 0;
        for(j = 0; j <= row; j++) {//遍历col_c数组，找到它应存的位置
            if(col_c[j] == temp && vis_c[j] != 1) {
                res[j][col[j]++] = i;//存入
                if(col[j] == col_c[j]) {
                    vis_c[j] = 1;
                }
                flag = 1;
                break;
            }
        }
        if(flag == 0) {//flag为0即为没找到应存的位置
            ++row;//另起一行存储
            col_c[row] = temp;//记录当前行可以存进元素的个数
            res[row][col[row]++] = i;//存入
            if(col[row] == col_c[row]) {
                vis_c[row] = 1;
            }
        }
    }
    *returnSize = row + 1;
    *returnColumnSizes = col;
    return res;
}



