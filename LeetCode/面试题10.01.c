#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int a1 = 0,b1 = 0,temp[m + n],temp1 = 0;//a1为A数组的指针，b1为B数组指针
    while(a1 < m && b1 < n) {
        if(A[a1] <= B[b1]) {//比较大小然后存进临时数组中
            temp[temp1++] = A[a1++];
        }
        else {
            temp[temp1++] = B[b1++];
        }
    }
    //将剩余元素存进临时数组中
    while(a1 < m) {
        temp[temp1++] = A[a1++];
    }
    while(b1 < n) {
        temp[temp1++] = B[b1++];
    }
    //将临时数组中的元素重新存进A数组
    for(int i = 0; i < m + n; i++) {
        A[i] = temp[i];
    }
}
