#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row;

void dfs(int *nums,int *map,int numsSize,int colu,int *col,int **arr) {
    int i;
    if(colu==numsSize) {//�����������������֮��
        if(row==0) {//����ǵ�0��
            col[row]=numsSize;
            row=row+1;////��һ�����������һ��
            for(i=0;i<numsSize;i++)//��������������һ���У���Ϊ֮����õ�
                arr[row][i]=arr[row-1][i];
        }
        if(row>0) {//����ǵ�0��֮�����
            int flag=0,j,k;
            k=row;
            for(i=row-1;i>=0;i--) {//ͨ���Ƚ����ж��Ƿ����ظ�����
                for(j=0;j<numsSize;j++) {
                    if(arr[k][j]!=arr[i][j])
                        break;
                    if(arr[k][j]==arr[i][j]) {
                        if(j==numsSize-1) {//��������к�֮ǰ��ͬ������
                            flag=1;//flag���Ϊ1
                            break;
                        }
                    }
                }
                if(flag==1)//flagΪ1��Ϊ�ҵ��ظ�
                    break;//����ѭ��
            }
            if(flag==0) {//��û�ҵ��ظ�����ʱ
                col[row]=numsSize;
                row=row+1;//�м�1���Ա��´εĴ洢
                for(i=0;i<numsSize;i++)//��������������һ���У���Ϊ֮����õ�
                    arr[row][i]=arr[row-1][i];
            }
        }
        return ;
    }
    for(i=0;i<numsSize;i++) {//������Ŀ������һά����
        if(map[i]==0) {//�ҵ�û����ǵ�����
            arr[row][colu]=nums[i];//�����ά������
            map[i]=1;//�������ֱ��
            dfs(nums,map,numsSize,colu+1,col,arr);//�ݹ����
            map[i]=0;//�ݹ���û��˳���ʱ��Ҫ�������ֵı�����
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,colu=0;//colu��ʾ���������ά�������һ��
    row=0;//ȫ�ֱ�������ʾ���������ά�������һ��
    int *col=(int *)malloc(5000*sizeof(int));
    int **arr =(int **)malloc(sizeof(int*)*5000);//���ٶ�ά����
    for(i=0; i<5000; i++)
        arr[i]=(int *)malloc(sizeof(int)*100);
    int *map=(int *)malloc(numsSize*sizeof(int));//����һ��һά�ı������
    memset(map,0,numsSize*sizeof(int));//�����ʼ��
    dfs(nums,map,numsSize,colu,col,arr);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
