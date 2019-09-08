#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row,n1;
//sum���Ѽӵ���ʱ�����е�Ԫ�ص��ܺͣ�i���Ӽ���Ԫ�صĸ�����m��¼temp����Ԫ�ش洢��λ�ã�num��¼nums�����б�������Ԫ�ص�λ��
void dfs(int **arr,int *nums,int *temp,int *col,int sum,int i,int m,int num,int numsSize) {
    if(i==0&&sum==n1) {//��Ԫ�ظ���Ϊ0���Һ�Ϊ����ֵ
        col[row]=m;//��¼����Ԫ�صĸ���
        for(int i=0;i<m;i++)//��Ԫ�طŽ�arr������
            arr[row][i]=temp[i];
        row=row+1;//��ʼ��¼��һ��
        return ;
    }
    for(;num<numsSize;num++) {
        if(nums[num]>n1-sum)//�жϵ�ǰ�����Ƿ���Լӵ���ʱ������
           continue;
        temp[m]=nums[num];//�����ʱ����
        i=i-1;//������һ
        sum=sum+nums[num];//�ܺͼ��ϵ�ǰԪ��
        dfs(arr,nums,temp,col,sum,i,m+1,num+1,numsSize);
        i=i+1;//��dfs������ʱ��������һ
        sum=sum-nums[num];//��dfs������ʱ��Ҫ��ȥ��ǰԪ��
    }
    return ;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int nums[10],i,numsSize=0,sum=0;//nums����洢1��9��9����
    n1=n;//n1��ȫ�ֱ�������¼����ֵn
    for(i=1;i<=9;i++)
        nums[numsSize++]=i;
    row=0;
    int temp[numsSize];//��ʱ��������е�Ԫ��
    int *col=(int *)malloc(1000*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�����
    int **arr =(int **)malloc(sizeof(int*)*1000);//���ٶ�ά����
    for(i=0; i<1000; i++)
        arr[i]=(int *)malloc(sizeof(int)*k);
    dfs(arr,nums,temp,col,sum,k,0,0,numsSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
