#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)//�Ƚ���
{
    return *(int *)a-*(int *)b;//��С��������
}

int row;
//i���Ӽ���Ԫ�صĸ�����m��¼temp����Ԫ�ش洢��λ�ã�num��¼nums�����б�������Ԫ�ص�λ��
void dfs(int **arr,int *nums,int *temp,int *col,int i,int m,int num,int numsSize) {
    if(i==0) {//������Ϊ0ʱ
        int flag;//��������Ƿ��ظ�
        if(row==1) {//��һ��Ҫ���ȥ
            col[row]=m;//��¼����Ԫ�صĸ���
            for(int j=0;j<m;j++)//��Ԫ�طŽ�arr������
                arr[row][j]=temp[j];
            row=row+1;//��ʼ��¼��һ��
        }
        else{//�ӵڶ��п�ʼҪ��֮ǰ�������бȽ��ж��Ƿ��ظ�
            for(int u=row-1;u>=1;u--) {
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
    for(;num<numsSize;num++) {
        temp[m]=nums[num];//�����ʱ������
        i=i-1;//Ԫ�ظ�����1
        dfs(arr,nums,temp,col,i,m+1,num+1,numsSize);
        i=i+1;//��dfs��������Ҫ��Ԫ�ظ������¼�1
    }
    return ;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i;
    row=1;//�ӵ�һ�п�ʼ�洢
    qsort(nums,numsSize,sizeof(nums[0]),cmp);//�Ƚ�nums��������
    int n=(int)pow(2,numsSize);//�����Ӽ���������Ϊ���ظ��Ӽ�����ʵ�ʵ��Ӽ�����������٣�
    int *temp=(int *)malloc(numsSize*sizeof(int));//��ʱ��������е�Ԫ��
    int *col=(int *)malloc(n*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�����
    int **arr =(int **)malloc(sizeof(int*)*n);//���ٶ�ά����
    for(i=0; i<n; i++)
        arr[i]=(int *)malloc(sizeof(int)*1000);
    col[0]=0;//�Ӽ�֮һ�ǿռ���
    for(i=1;i<=numsSize;i++) {//iΪ�Ӽ���Ԫ�صĸ���
        dfs(arr,nums,temp,col,i,0,0,numsSize);
    }
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
