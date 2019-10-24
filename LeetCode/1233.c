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
    qsort((void*)folder, folderSize, sizeof(char *), cmp);//����ά���鰴���ֵ�������
    int i,j,k,row = 0;
    char **res = (char **)malloc(sizeof(char*) * folderSize);//���ٶ�ά����
    for(i = 0; i < folderSize; i++)
        res[i] = (char *)malloc(sizeof(char) * 105);

    for(i = 0; i < folderSize; i++) {
        for(j = i + 1; j < folderSize; j++) {//�жϵ�i�������Ƿ����������ļ���
            for(k = 0; k < strlen(folder[i]); k++) {
                if(folder[i][k] != folder[j][k])
                    break;
            }
            if(k >= strlen(folder[i]) && folder[j][k] == '/')//��������˵���ǵ�i�������ļ���
                continue;//�ж���һ��
            else {//����
                strcpy(res[row],folder[i]);//������������
                row++;
                i = j - 1;//�´�i�����ļ��е�Ѱ��Ҫ�����������Ŀ�ʼ
                break;
            }
        }
        if(j >= folderSize) {//�ַ���ȫ�����꣬���ǵ�i�������ļ���
            strcpy(res[row],folder[i]);//����������
            row++;
            break;
        }
    }
    *returnSize = row;//��¼�¶�ά���������
    return res;
}
