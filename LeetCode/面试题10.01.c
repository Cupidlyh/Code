#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int a1 = 0,b1 = 0,temp[m + n],temp1 = 0;//a1ΪA�����ָ�룬b1ΪB����ָ��
    while(a1 < m && b1 < n) {
        if(A[a1] <= B[b1]) {//�Ƚϴ�СȻ������ʱ������
            temp[temp1++] = A[a1++];
        }
        else {
            temp[temp1++] = B[b1++];
        }
    }
    //��ʣ��Ԫ�ش����ʱ������
    while(a1 < m) {
        temp[temp1++] = A[a1++];
    }
    while(b1 < n) {
        temp[temp1++] = B[b1++];
    }
    //����ʱ�����е�Ԫ�����´��A����
    for(int i = 0; i < m + n; i++) {
        A[i] = temp[i];
    }
}
