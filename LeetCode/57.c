#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int num[intervalsSize+1][2],i,row = 0,flag = 0;
    //将新区间按左边界的大小插入到区间列表中
    for(i=0;i<intervalsSize;i++) {//将区间列表的左边界值小于等于新区间左边界的存入num中
        if(intervals[i][0]<=newInterval[0]) {
            num[row][0] = intervals[i][0];
            num[row][1] = intervals[i][1];
            row++;
        }
        else {//新区间的存入
            num[row][0] = newInterval[0];
            num[row][1] = newInterval[1];
            row++;
            flag = 1;//如果新区间插入进去了，标记为1
            break;//新区间插入进取后就跳出循环
        }
    }
    for(;i<intervalsSize;i++) {//将区间列表左边界值大于新区间的左边界值存入num中（后半部分都是）
        num[row][0] = intervals[i][0];
        num[row][1] = intervals[i][1];
        row++;
    }
    if(intervalsSize == 0 || flag == 0) {//当所给的区间列表为空时或者新区间未插入进去（flag未被标记）
        num[row][0] = newInterval[0];
        num[row][1] = newInterval[1];
    }

    //区间合并
    row = 0;
    int **arr = (int **)malloc(sizeof(int *)*1000);//开辟二维数组
    for(i=0;i<1000;i++)
        arr[i] = (int *)malloc(sizeof(int)*2);
    for(i=0;i<intervalsSize+1;i++) {
        arr[row][0] = num[i][0];
        arr[row][1] = num[i][1];
        while(i<intervalsSize && arr[row][1]>=num[i+1][0]) {//如果后一行的左边界小于等于前一行的右边界就说明可以合并
            arr[row][1] = arr[row][1]>num[i+1][1]?arr[row][1]:num[i+1][1];//合并后的区间的右边界要选择大的那一个
            i = i + 1;
        }
        row = row + 1;
    }
    *returnSize = row;
    *returnColumnSizes = (int *)malloc(sizeof(int)*row);
    for(i=0;i<row;i++)
        (*returnColumnSizes)[i] = 2;
    return arr;
}
