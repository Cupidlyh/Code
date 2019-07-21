#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;//存储数组的元素
    int len;//存储数组的长度
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->len=numsSize;
    if(numsSize>0){//只有当传进来的数组长度大于0时
                  //才将传进来的数组赋值给数组arr
        obj->arr=nums;
    }
    return obj;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    int *nums=(int *)malloc(1000*sizeof(int));
    memset(nums,0,sizeof(1000*sizeof(int)));
    if(obj->len>0){//只有当数组的长度大于0时
                   //才将它置为初始状态
        nums=obj->arr;
    }
    *retSize=obj->len;
    return nums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    int i,j=0,k,array[1000]={0};//数组array为标记数组
    int *arr1=(int *)malloc(1000*sizeof(int));
    memset(arr1,0,sizeof(1000*sizeof(int)));
    for(i=0;i<obj->len;i++){
        if(j==0){//第一次随机取数要留着
                 //rand为随机取数的函数
        k=rand()%obj->len;//随机取数之后在对数组长度求余是为了使随机数的范围落在
                          //[0——obj->len-1]这个范围内，与数组的下标对应
        array[k]=1;
        }
        else{//从第二次开始要判断随机取出来的数字是否被标记过
            //如果被标记了，重新随机取数
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
