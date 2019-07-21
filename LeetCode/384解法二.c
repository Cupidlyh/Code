//洗牌算法
typedef struct {
    int *arr;//存储数组的元素
    int ar[1000];//备份元素，存在这里的不做更改
    int len;//存储数组的长度
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->len=numsSize;
    if(numsSize>0){//只有当传进来的数组长度大于0时
                             //才将传进来的数组赋值给数组arr和ar
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
    if(obj->len>0){//只有当数组的长度大于0时
                            //才将它置为初始状态
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
          //rand为随机取数的函数
        rnd=rand()%(obj->len-i)+i;这种写法可以实现在[i,obj->len-1]区间内的取随机数
        tmp=arr1[i];//交换
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