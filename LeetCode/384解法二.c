//ϴ���㷨
typedef struct {
    int *arr;//�洢�����Ԫ��
    int ar[1000];//����Ԫ�أ���������Ĳ�������
    int len;//�洢����ĳ���
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->len=numsSize;
    if(numsSize>0){//ֻ�е������������鳤�ȴ���0ʱ
                             //�Ž������������鸳ֵ������arr��ar
        obj->arr=nums;
        for(int i=0;i<numsSize;i++)
            obj->ar[i]=nums[i];
    }
    return obj;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    int *nums=(int *)malloc(1000*sizeof(int));
    memset(nums,0,sizeof(1000*sizeof(int)));
    if(obj->len>0){//ֻ�е�����ĳ��ȴ���0ʱ
                            //�Ž�����Ϊ��ʼ״̬
        for(int i=0;i<obj->len;i++)
            nums[i]=obj->ar[i];
    }
    *retSize=obj->len;
    return nums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    int i,j=0,tmp,rnd;
    int *arr1=(int *)malloc(1000*sizeof(int));
    memset(arr1,0,sizeof(1000*sizeof(int)));
    arr1=obj->arr;
    for(i=0;i<obj->len;i++){
          //randΪ���ȡ���ĺ���
        rnd=rand()%(obj->len-i)+i;����д������ʵ����[i,obj->len-1]�����ڵ�ȡ�����
        tmp=arr1[i];//����
        arr1[i]=arr1[rnd];
        arr1[rnd]=tmp;
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