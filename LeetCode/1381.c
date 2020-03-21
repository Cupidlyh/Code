#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max,top;
    int arr[10000];
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj -> max = maxSize;
    obj -> top = 0;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if(obj -> top != obj -> max) {
        obj -> arr[obj -> top++] = x;
    }
}

int customStackPop(CustomStack* obj) {
    if(obj -> top == 0)
        return -1;
    int res = obj -> arr[obj -> top - 1];
    obj -> top--;
    return res;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if(k > obj -> max)
        k = obj -> max;
    for(int i = 0; i < k; i++)
        obj -> arr[i] += val;
}

void customStackFree(CustomStack* obj) {
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/
