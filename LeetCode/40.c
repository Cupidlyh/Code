#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b) {//�Ƚ���
    return *(int *)a-*(int *)b;//��С��������
}

int row,n;
//sum���Ѽӵ���ʱ�����е�Ԫ�ص��ܺͣ�m��¼temp����Ԫ�ش洢��λ�ã�num��¼candidates�����б�������Ԫ�ص�λ��
void dfs(int **arr,int *candidates,int *temp,int *col,int sum,int m,int num,int candidatesSize) {
    if(sum==n) {//����Ϊ��Ŀ����ֵʱ
        int flag;
        if(row==0) {//��0��һ��Ҫ�ȴ洢��
            col[row]=m;//��¼����Ԫ�صĸ���
            for(int j=0;j<m;j++)//��Ԫ�طŽ�arr������
                arr[row][j]=temp[j];
            row=row+1;//��ʼ��¼��һ��
        }
        else{//�ӵ�һ�п�ʼҪ��֮ǰ�������бȽ��ж��Ƿ��ظ�
            for(int u=row-1;u>=0;u--) {
                flag=0;
                if(col[u]!=m) {
                    flag=1;
                    continue;
                }
                for(int v=0;v<col[u];v++)
                    if(arr[u][v]!=temp[v]) {
                        flag=1;
                        break;
                    }
                if(flag==1)
                    continue;
                else
                    break;
            }
        }
        if(flag==1) {//���ظ�ʱ
            col[row]=m;//��¼����Ԫ�صĸ���
            for(int j=0;j<m;j++)//��Ԫ�طŽ�arr������
                arr[row][j]=temp[j];
            row=row+1;//��ʼ��¼��һ��
        }
        return ;
    }
    for(;num<candidatesSize;num++) {
        if(candidates[num]>n-sum)//�жϵ�ǰ�����Ƿ���Լӵ���ʱ������
            continue;
        temp[m]=candidates[num];//�����ʱ������
        sum=sum+candidates[num];//�ܺͼ��ϵ�ǰԪ��
        dfs(arr,candidates,temp,col,sum,m+1,num+1,candidatesSize);
        sum=sum-candidates[num];//��dfs������ʱ��Ҫ��ȥ��ǰԪ��
    }
    return ;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(candidates[0]),cmp);//����
    n=target;//n��ȫ�ֱ�������¼����ֵ
    row=0;
    int sum=0,temp[candidatesSize],i;//temp����ʱ��Ԫ�ص�����
    int *col=(int *)malloc(1000*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�����
    int **arr =(int **)malloc(sizeof(int*)*1000);//���ٶ�ά����
    for(i=0; i<1000; i++)
        arr[i]=(int *)malloc(sizeof(int)*candidatesSize);
    dfs(arr,candidates,temp,col,sum,0,0,candidatesSize);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
