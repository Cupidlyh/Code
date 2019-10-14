#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2){//�Ƚ���
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals,intervalsSize, sizeof(intervals[0]),cmp);//����ά���鰴����߽�Ĵ�С�����д�С��������
    int i,row = 0;
    int **arr = (int **)malloc(sizeof(int *)*1000);//���ٶ�ά����
    for(i=0;i<1000;i++)
        arr[i] = (int *)malloc(sizeof(int)*2);
    for(i=0;i<intervalsSize;i++) {
        arr[row][0] = intervals[i][0];
        arr[row][1] = intervals[i][1];
        while(i<intervalsSize-1 && arr[row][1]>=intervals[i+1][0]) {//�����һ�е���߽�С�ڵ���ǰһ�е��ұ߽��˵�����Ժϲ�
            arr[row][1] = arr[row][1]>intervals[i+1][1]?arr[row][1]:intervals[i+1][1];//�ϲ����������ұ߽�Ҫѡ������һ��
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
