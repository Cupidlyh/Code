#include <stdio.h>
#include <stdlib.h>

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int row = 0,i,j,vis[1005] = {0};//vis为标记数组用来标记区间是否被覆盖
    for(i = 0; i < intervalsSize; i++) {//遍历二维数组，将每个区间和所有的区间进行比较看是否能够覆盖其他区间
        for(j = 0; j < intervalsSize; j++) {
            if(vis[i] == 1)
                break;
            if(i == j || vis[j] == 1)
                continue;
            if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])//j被i区间覆盖
                vis[j] = 1;//标记
        }
    }
    for(i = 0; i < intervalsSize; i++)
        if(vis[i] == 0)//区间未被覆盖
            row++;//区间数目加一
    return row;
}
