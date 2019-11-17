#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b)
{
     return(*(char *)a-*(char *)b);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    int book[strsSize],i,j;//bookΪ�������
    char **strscpy = (char **)malloc(sizeof(char *) * strsSize);//��strs�����е��ַ�������strscpy����
    for(i = 0; i < strsSize; i++) {
        book[i] = 0;//���������0
        strscpy[i] = (char *)malloc(sizeof(char) * strlen(strs[i]) + 1);
        strcpy(strscpy[i], strs[i]);
        qsort(strscpy[i],strlen(strscpy[i]),sizeof(strscpy[i][0]),cmp);//��ÿһ�е��ַ�����������
    }
    char ***res = (char ***)malloc(sizeof(char **)*strsSize);//������ά�����¼���
    int row = 0,col = 0;//row��¼������ά����Ĳ�����col��¼��ά����ÿһ�������
    for(i = 0; i < strsSize; i++) {//����������ά��stscpy����
        if(book[i] == 1)//�����ǰ�б���Ǿ�����
            continue;
        book[i] = 1;//��ǵ�ǰ��
        res[row] = (char **)malloc(sizeof(char*) * strsSize);
        res[row][col] = (char *)malloc(sizeof(char) * strlen(strs[i]) + 1);
        strcpy(res[row][col++],strs[i]);//����ǰ�е��ַ���������ά�����row���col��
        for(j = i + 1; j < strsSize; j++) {
            if(strcmp(strscpy[i],strscpy[j]) == 0) {//��i�е��ַ����ͺ���ÿһ�е��ַ������бȽϣ������ͬ
                book[j] = 1;//���б��
                res[row][col] = (char *)malloc(sizeof(char) * strlen(strs[j]) + 1);
                strcpy(res[row][col++],strs[j]);//�浽��ά�����row���col��
            }
        }
        (*returnColumnSizes)[row] = col;
        col = 0;//���¼�¼��һ�������
        row++;//������1
    }
    *returnSize = row;
    return res;
}
