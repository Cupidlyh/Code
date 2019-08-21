#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;//队列的头指针
    int arr[10000];
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj=(MyStack *)malloc(sizeof(MyStack));
    obj->top=0;
    memset(obj->arr,0,sizeof(obj->arr));//数组的初始化
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->arr[obj->top]=x;
    obj->top++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->arr[--obj->top];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->arr[obj->top-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top==0)
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
