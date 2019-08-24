#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a,const void *b)//�Ƚ���
{
    return *(int *)a-*(int *)b; //��С��������
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  int i,left,right,row=0,s;
  int *col=(int *)malloc(17000*sizeof(int));
  qsort(nums,numsSize,sizeof(nums[0]),cmp);//������
  int **arr =(int **)malloc(sizeof(int*)*17000);//arrΪ��ά����
    for(i=0; i<17000; i++)
        arr[i]=(int *)malloc(sizeof(int)*3);
    for(i=0;i<numsSize-2;i++) {//��������
        if(i>0&&nums[i]==nums[i-1])//ȥ��
            continue;
        left=i+1;//��ָ��
        right=numsSize-1;//��ָ��
        while(left<right) {//ѭ��������
            s=nums[i]+nums[left]+nums[right];
            if(s<0)
                left++;
            if(s>0)
                right--;
            if(s==0) {//�ҵ���
                arr[row][0]=nums[i];
                arr[row][1]=nums[left];
                arr[row][2]=nums[right];
                col[row]=3;
                row++;
                while(left<right&&nums[left]==nums[left+1])//ȥ��
                    left++;
                while(left<right&&nums[right]==nums[right-1])//ȥ��
                    right--;
                left++;//
                right--;
            }
        }
    }
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
