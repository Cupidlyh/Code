#include <stdio.h>
#include <stdlib.h>

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int row = 0,i,j,vis[1005] = {0};//visΪ�������������������Ƿ񱻸���
    for(i = 0; i < intervalsSize; i++) {//������ά���飬��ÿ����������е�������бȽϿ��Ƿ��ܹ�������������
        for(j = 0; j < intervalsSize; j++) {
            if(vis[i] == 1)
                break;
            if(i == j || vis[j] == 1)
                continue;
            if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])//j��i���串��
                vis[j] = 1;//���
        }
    }
    for(i = 0; i < intervalsSize; i++)
        if(vis[i] == 0)//����δ������
            row++;//������Ŀ��һ
    return row;
}
