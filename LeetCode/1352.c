#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[40005];//�洢�ӽ�����Ԫ��
    int i;//��¼������±�λ��
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj -> i = 0;///�±�ĳ�ʼλ��
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num <= 100)//��Ŀ�������� 0 <= num <= 100
        obj -> arr[obj -> i++] = num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    int res = 1,j = obj -> i - 1;
    while(k > 0) {//�������k�����ֵĳ˻�
        res *= obj -> arr[j--];
        if(res == 0)
            break;
        k--;
    }
    return res;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);

 * int param_2 = productOfNumbersGetProduct(obj, k);

 * productOfNumbersFree(obj);
*/
