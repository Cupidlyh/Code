#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize){
    int i,j;
    int *arr1 = (int *)malloc(sizeof(int) * 10005);//�������
    for(i = 0; i < arrSize - 1; i++) {
        int temp = 0;
        for(j = i + 1; j < arrSize; j++) {//�ڵ�i��Ԫ���ұߵ�Ԫ������һ�����ֵ
            if(temp < arr[j])
                temp = arr[j];
        }
        arr1[i] = temp;
    }
    arr1[arrSize - 1] = -1;//���һ��Ԫ�ػ���-1
    *returnSize = arrSize;
    return arr1;
}
