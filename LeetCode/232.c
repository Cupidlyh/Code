#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int base;//栈底指针
    int top;//栈顶指针
    int arr[1000];

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj=(MyQueue *)malloc(sizeof(MyQueue));
    obj->base=0;
    obj->top=0;
    memset(obj->arr,0,sizeof(obj->arr));//数组初始化
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->arr[obj->top]=x;
    obj->top++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int res=obj->arr[obj->base];
    obj->base++;
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->base];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->base==obj->top)
        return true;
    return false;

}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
