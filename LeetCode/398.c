#include <stdio.h>
#include <stdlib.h>

typedef struct {//结构体
    int *arr;//数组
    int len;//数组长度
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));//创建一个结构体数组
    obj->arr = nums;
    obj->len = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int i=0,ans,num=0;//num用来记录与所给值相等数字的数量
    for(i=0; i<obj->len; i++){
        if(obj->arr[i] == target){//if开始的三行是核心代码，也是最重要的
            num++;
            ans=(rand()%num==0)?i:ans;//随机取样
        }
    }
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);//释放空间
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);

 * solutionFree(obj);
*/
