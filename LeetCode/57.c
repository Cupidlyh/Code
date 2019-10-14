#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int num[intervalsSize+1][2],i,row = 0,flag = 0;
    //�������䰴��߽�Ĵ�С���뵽�����б���
    for(i=0;i<intervalsSize;i++) {//�������б����߽�ֵС�ڵ�����������߽�Ĵ���num��
        if(intervals[i][0]<=newInterval[0]) {
            num[row][0] = intervals[i][0];
            num[row][1] = intervals[i][1];
            row++;
        }
        else {//������Ĵ���
            num[row][0] = newInterval[0];
            num[row][1] = newInterval[1];
            row++;
            flag = 1;//�������������ȥ�ˣ����Ϊ1
            break;//����������ȡ�������ѭ��
        }
    }
    for(;i<intervalsSize;i++) {//�������б���߽�ֵ�������������߽�ֵ����num�У���벿�ֶ��ǣ�
        num[row][0] = intervals[i][0];
        num[row][1] = intervals[i][1];
        row++;
    }
    if(intervalsSize == 0 || flag == 0) {//�������������б�Ϊ��ʱ����������δ�����ȥ��flagδ����ǣ�
        num[row][0] = newInterval[0];
        num[row][1] = newInterval[1];
    }

    //����ϲ�
    row = 0;
    int **arr = (int **)malloc(sizeof(int *)*1000);//���ٶ�ά����
    for(i=0;i<1000;i++)
        arr[i] = (int *)malloc(sizeof(int)*2);
    for(i=0;i<intervalsSize+1;i++) {
        arr[row][0] = num[i][0];
        arr[row][1] = num[i][1];
        while(i<intervalsSize && arr[row][1]>=num[i+1][0]) {//�����һ�е���߽�С�ڵ���ǰһ�е��ұ߽��˵�����Ժϲ�
            arr[row][1] = arr[row][1]>num[i+1][1]?arr[row][1]:num[i+1][1];//�ϲ����������ұ߽�Ҫѡ������һ��
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
