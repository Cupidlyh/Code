#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row;
//i���Ӽ���Ԫ�صĸ�����m��¼temp����Ԫ�ش洢��λ�ã�num��¼nums�����б�������Ԫ�ص�λ��
void dfs(int **arr,int *nums,int *temp,int *col,int i,int m,int num,int numsSize) {
    if(i==0) {//������Ϊ0ʱ
        col[row]=m;//��¼����Ԫ�صĸ���
        for(int j=0;j<m;j++)//��Ԫ�طŽ�arr������
            arr[row][j]=temp[j];
        row=row+1;//��ʼ��¼��һ��
        return ;
    }
    for(;num<numsSize;num++) {
        temp[m]=nums[num];//�����ʱ������
        i=i-1;//Ԫ�ظ�����1
        dfs(arr,nums,temp,col,i,m+1,num+1,numsSize);
        i=i+1;//��dfs��������Ҫ��Ԫ�ظ������¼�1
    }
    return ;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i;
    row=1;//�ӵ�һ�п�ʼ�洢
    int n=(int)pow(2,numsSize);//�����Ӽ��ĸ���
    int *temp=(int *)malloc(numsSize*sizeof(int));//��ʱ��������е�Ԫ��
    int *col=(int *)malloc(n*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�����
    int **arr =(int **)malloc(sizeof(int*)*n);//���ٶ�ά����
    for(i=0; i<n; i++)
        arr[i]=(int *)malloc(sizeof(int)*1000);
    col[0]=0;//�Ӽ�֮һ�ǿռ���
    for(i=1;i<=numsSize;i++) {//iΪ�Ӽ���Ԫ�صĸ���
        dfs(arr,nums,temp,col,i,0,0,numsSize);
    }
    *returnSize=n;
    *returnColumnSizes=col;
    return arr;
}
