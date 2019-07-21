#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;//�洢�����Ԫ��
    int len;//�洢����ĳ���
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->len=numsSize;
    if(numsSize>0){//ֻ�е������������鳤�ȴ���0ʱ
                  //�Ž������������鸳ֵ������arr
        obj->arr=nums;
    }
    return obj;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    int *nums=(int *)malloc(1000*sizeof(int));
    memset(nums,0,sizeof(1000*sizeof(int)));
    if(obj->len>0){//ֻ�е�����ĳ��ȴ���0ʱ
                   //�Ž�����Ϊ��ʼ״̬
        nums=obj->arr;
    }
    *retSize=obj->len;
    return nums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    int i,j=0,k,array[1000]={0};//����arrayΪ�������
    int *arr1=(int *)malloc(1000*sizeof(int));
    memset(arr1,0,sizeof(1000*sizeof(int)));
    for(i=0;i<obj->len;i++){
        if(j==0){//��һ�����ȡ��Ҫ����
                 //randΪ���ȡ���ĺ���
        k=rand()%obj->len;//���ȡ��֮���ڶ����鳤��������Ϊ��ʹ������ķ�Χ����
                          //[0����obj->len-1]�����Χ�ڣ���������±��Ӧ
        array[k]=1;
        }
        else{//�ӵڶ��ο�ʼҪ�ж����ȡ�����������Ƿ񱻱�ǹ�
            //���������ˣ��������ȡ��
            k=rand()%obj->len;
            while(array[k]==1)
            k=rand()%obj->len;
            array[k]=1;
        }
        arr1[j++]=obj->arr[k];
    }
    *retSize=obj->len;
    return arr1;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/
