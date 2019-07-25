#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;//栈
    int top;//栈的指针
    int *arr1;//辅助栈
    int top1;//辅助栈的指针
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));//开辟一个栈
    obj->top=0;
    obj->top1=1;
    obj->arr=(int *)malloc(10000*sizeof(int));//开辟栈中的数组
    obj->arr1=(int *)malloc(10000*sizeof(int));
    memset(obj->arr,0,10000*sizeof(int));//栈的数组的初始化
    memset(obj->arr1,0,10000*sizeof(int));
    return obj;
}

void minStackPush(MinStack* obj, int x) {//压栈
    if(obj->top==0){//第一个传进来的元素要进到辅助栈中，方便后来的比较
        obj->arr1[obj->top1]=x;
        obj->top1++;
    }
    if(obj->top!=0&&x<=obj->arr1[obj->top1-1]){//比辅助栈的栈顶元素小于或等于就进到辅助栈中
        obj->arr1[obj->top1]=x;
        obj->top1++;
    }
    obj->arr[obj->top]=x;
    obj->top++;
}

void minStackPop(MinStack* obj) {//删除栈顶元素
    if(obj->arr[obj->top-1]==obj->arr1[obj->top1-1])//如果要删除的这个元素等于辅助栈的栈顶元素
        obj->top1=obj->top1-1;                      //则辅助栈的栈顶元素也删除
    obj->top=obj->top-1;
}

int minStackTop(MinStack* obj) {//取栈顶元素的值
    int a=obj->arr[obj->top-1];
    return a;
}

int minStackGetMin(MinStack* obj) {//获取栈中的最小值
     int min=obj->arr1[obj->top1-1];//辅助栈的栈顶元素就是栈中的最小值
    return min;
}

void minStackFree(MinStack* obj) {//释放栈
    free(obj);
}
