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
        for(int i=0;i<m;i++)//��Ԫ�طŽ�arr������
            arr[row][i]=temp[i];
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

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int nums[1000]={0},numsSize=0,i;//num����洢������˵��1��n������
    for(i=1;i<=n;i++)
        nums[numsSize++]=i;
    row=0;
    int temp[numsSize];//��ʱ��������е�Ԫ��
    int *col=(int *)malloc(10000*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�����
    int **arr =(int **)malloc(sizeof(int*)*10000);//���ٶ�ά����
    for(i=0; i<10000; i++)
        arr[i]=(int *)malloc(sizeof(int)*k);
    dfs(arr,nums,temp,col,k,0,0,numsSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
