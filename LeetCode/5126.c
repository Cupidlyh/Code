#include <stdio.h>
#include <stdlib.h>

int findSpecialInteger(int* arr, int arrSize){
    int i;
    double k = arrSize / 4,num = 0;//k�Ǽ���ռ��25%��Ԫ�����������num����������Ԫ������
    for(i = 0; i < arrSize - 1; i++) {//��������
        if(arr[i] == arr[i + 1]) {
            num++;//��¼Ԫ�س��ֵĴ���
            if(num >= k) {//�����ķ�֮һ������ѭ��
                break;
            }
        }
        else {
            num = 0;//���÷����´μ�¼
        }
    }
    return arr[i];
}
