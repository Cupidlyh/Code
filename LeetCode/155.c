#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;//ջ
    int top;//ջ��ָ��
    int *arr1;//����ջ
    int top1;//����ջ��ָ��
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));//����һ��ջ
    obj->top=0;
    obj->top1=1;
    obj->arr=(int *)malloc(10000*sizeof(int));//����ջ�е�����
    obj->arr1=(int *)malloc(10000*sizeof(int));
    memset(obj->arr,0,10000*sizeof(int));//ջ������ĳ�ʼ��
    memset(obj->arr1,0,10000*sizeof(int));
    return obj;
}

void minStackPush(MinStack* obj, int x) {//ѹջ
    if(obj->top==0){//��һ����������Ԫ��Ҫ��������ջ�У���������ıȽ�
        obj->arr1[obj->top1]=x;
        obj->top1++;
    }
    if(obj->top!=0&&x<=obj->arr1[obj->top1-1]){//�ȸ���ջ��ջ��Ԫ��С�ڻ���ھͽ�������ջ��
        obj->arr1[obj->top1]=x;
        obj->top1++;
    }
    obj->arr[obj->top]=x;
    obj->top++;
}

void minStackPop(MinStack* obj) {//ɾ��ջ��Ԫ��
    if(obj->arr[obj->top-1]==obj->arr1[obj->top1-1])//���Ҫɾ�������Ԫ�ص��ڸ���ջ��ջ��Ԫ��
        obj->top1=obj->top1-1;                      //����ջ��ջ��Ԫ��Ҳɾ��
    obj->top=obj->top-1;
}

int minStackTop(MinStack* obj) {//ȡջ��Ԫ�ص�ֵ
    int a=obj->arr[obj->top-1];
    return a;
}

int minStackGetMin(MinStack* obj) {//��ȡջ�е���Сֵ
     int min=obj->arr1[obj->top1-1];//����ջ��ջ��Ԫ�ؾ���ջ�е���Сֵ
    return min;
}

void minStackFree(MinStack* obj) {//�ͷ�ջ
    free(obj);
}
