#include <stdio.h>
#include <stdlib.h>

typedef struct {//�ṹ��
    int *arr;//����
    int len;//���鳤��
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));//����һ���ṹ������
    obj->arr = nums;
    obj->len = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int i=0,ans,num=0;//num������¼������ֵ������ֵ�����
    for(i=0; i<obj->len; i++){
        if(obj->arr[i] == target){//if��ʼ�������Ǻ��Ĵ��룬Ҳ������Ҫ��
            num++;
            ans=(rand()%num==0)?i:ans;//���ȡ��
        }
    }
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);//�ͷſռ�
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);

 * solutionFree(obj);
*/
