#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b) {
    const int p2 = *(const int*)a;
    const int p1 = *(const int*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}//�Ӵ�С����

int minSetSize(int* arr, int arrSize){
    int set[100005] = {0},i,sum = 0;
    for(i = 0; i < arrSize; i++) {//���������¼ÿ��Ԫ�س��ֵĴ���
        set[arr[i]]++;
    }
    qsort(set,100005,sizeof(set[0]),cmp);//����
    for(i = 0; i < 100005; i++) {
        sum = sum + set[i];
        if(sum >= (arrSize / 2))//ɾ��Ԫ������Ҫ���ڵ�������Ԫ�ص�һ��
            break;
    }
    return i + 1;
}
