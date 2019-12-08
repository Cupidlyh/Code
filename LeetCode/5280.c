#include <stdio.h>
#include <stdlib.h>



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    //vis_c�������col_c�����Ƿ��Ѿ�������col_c�����¼������鵱ǰ�п��Դ��Ԫ�صĸ���
    int i,row = 0,vis_c[505] = {0},col_c[505] = {0},temp,j;
    int **res = (int **)malloc(sizeof(int *) * 505);//��¼����Ķ�ά����
    for(i = 0; i < 505; i++) {
        res[i] = (int *)malloc(sizeof(int) * 505);
    }

    int *col = (int *)malloc(sizeof(int) * 505);//��¼ÿ��Ԫ�ظ�����һά����
    for(i = 0; i < 505; i++)
        col[i] = 0;

    col_c[row] = groupSizes[row];//��¼��ǰ�п��Դ��Ԫ�صĸ���
    res[row][col[row]++] = 0;//�±������������
    if(col[row] == col_c[row]) {//����Ѿ�����
        vis_c[row] = 1;//���
    }
    for(i = 1; i < groupSizesSize; i++) {//������Ŀ������������
        temp = groupSizes[i];
        int flag = 0;
        for(j = 0; j <= row; j++) {//����col_c���飬�ҵ���Ӧ���λ��
            if(col_c[j] == temp && vis_c[j] != 1) {
                res[j][col[j]++] = i;//����
                if(col[j] == col_c[j]) {
                    vis_c[j] = 1;
                }
                flag = 1;
                break;
            }
        }
        if(flag == 0) {//flagΪ0��Ϊû�ҵ�Ӧ���λ��
            ++row;//����һ�д洢
            col_c[row] = temp;//��¼��ǰ�п��Դ��Ԫ�صĸ���
            res[row][col[row]++] = i;//����
            if(col[row] == col_c[row]) {
                vis_c[row] = 1;
            }
        }
    }
    *returnSize = row + 1;
    *returnColumnSizes = col;
    return res;
}



