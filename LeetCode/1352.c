#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[40005];//存储加进来的元素
    int i;//记录数组的下标位置
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj -> i = 0;///下标的初始位置
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num <= 100)//题目告诉我们 0 <= num <= 100
        obj -> arr[obj -> i++] = num;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    int res = 1,j = obj -> i - 1;
    while(k > 0) {//计算最后k个数字的乘积
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
