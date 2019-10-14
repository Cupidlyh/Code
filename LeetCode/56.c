#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2){//比较器
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals,intervalsSize, sizeof(intervals[0]),cmp);//将二维数组按照左边界的大小来进行从小到大排序
    int i,row = 0;
    int **arr = (int **)malloc(sizeof(int *)*1000);//开辟二维数组
    for(i=0;i<1000;i++)
        arr[i] = (int *)malloc(sizeof(int)*2);
    for(i=0;i<intervalsSize;i++) {
        arr[row][0] = intervals[i][0];
        arr[row][1] = intervals[i][1];
        while(i<intervalsSize-1 && arr[row][1]>=intervals[i+1][0]) {//如果后一行的左边界小于等于前一行的右边界就说明可以合并
            arr[row][1] = arr[row][1]>intervals[i+1][1]?arr[row][1]:intervals[i+1][1];//合并后的区间的右边界要选择大的那一个
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
