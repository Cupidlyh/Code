#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//map��¼�ʺ���õ�λ��
int num,map[1000];

void dfs(int k,int n,char ***res){
    if(k == n+1){//��k����n+1ʱ��˵���ҵ���һ�ְڷŷ�ʽ
        int x,y = 0;
        for(x = 1; x < k; x++)
            res[num][y++][map[x]-1] = 'Q';
        num++;//num�Ǽ�¼n�ʺ�����İڷŷ�ʽ������
        return;//����
    }
    int i,j,flag;
    for(i = 1; i <= n; i++){
        map[k] = i;//���Ե�ǰ�ʺ������õ�λ��
        flag = 1;
        for(j = 1; j < k; j++){//��ǰ�ʺ��λ����֮ǰ���лʺ��λ�ý����ж�
            if(map[j] == i || i - k == map[j] - j || i + k == map[j] + j){//��������һ����˵���ʺ�ڷŵ�λ�ò���ȷ
                flag = 0;
                break;
            }
        }
        if(flag == 1)//�ʺ�λ����ȷ
            dfs(k+1,n,res);//�ݹ�����ж���һ���ʺ��λ��
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    memset(map,0,sizeof(map));//��ʼ��
    num = 0;//��¼�ж����ֽⷨ
    int i,j,k;
    char ***res;
    res = (char ***)malloc(sizeof(char **)*1000);//������ά����
    for(i = 0;i < 1000;i++) {
        res[i] = (char **)malloc(sizeof(char*) * (n+1));
        for(j = 0;j < n;j++) {
	        res[i][j] = (char *)malloc(sizeof(char) * (n+1));
		    for(k = 0;k < n;k++){
			    res[i][j][k] = '.';//�����ж���ʼ��Ϊ'.'
                res[i][j][k+1] = '\0';//��Ϊ���ַ������������Ҫ��\0
            }
	    }
    }
    dfs(1,n,res);
    *returnSize = num;//�ⷨ������
    *returnColumnSizes = (int *)malloc(sizeof(int) * num);
    for(i=0;i<num;i++)
        (*returnColumnSizes)[i] = n;//��¼�Ӷ�ά���������
    return res;
}
