#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** printVertically(char* s, int* returnSize){
    int i,j,row = 0,col = 0;
    *returnSize = 0;
    char **arr = (char **)malloc(sizeof(char*)*205);//���ٶ�ά����
    for(i=0; i<205; i++) {
        arr[i]=(char *)malloc(sizeof(char)*205);
        for(j = 0;j < 205; j++)
            arr[i][j] = ' ';//�����ʼ���ɿո�
    }

    for(i = 0; i < strlen(s); i++) {//���������ַ����еĵ������Ŵ洢����
        if(s[i] == ' ') {
            *returnSize = (*returnSize) > row ? (*returnSize) : row;
            col++;
            row = 0;
            continue;
        }
        else {
            arr[row++][col] = s[i];
        }
    }
    *returnSize = (*returnSize) > row ? (*returnSize) : row;
    for(i = 0; i < *returnSize; i++) {//��Ϊβ���������пո񣬲���β��Ҫ����ֹ�������ԴӶ�ά����ÿһ�е�β����ʼ��ǰ����
        for(j = col + 1; j >= 0; j--) {
            if(arr[i][j] == ' ')
                arr[i][j] = '\0';
            else
                break;
        }
    }
    return arr;
}


