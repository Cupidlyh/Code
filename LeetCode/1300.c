#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b) {
    const int p1 = *(const int*)a;
    const int p2 = *(const int*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}//��С��������

int findBestValue(int* arr, int arrSize, int target){
    qsort(arr,arrSize,sizeof(arr[0]),cmp);//����
    int i,sum = 0,res = 100000,j,temp;
    for(i = 0; i < arrSize; i++) {//�Ƚ�����Ԫ��֮����һ��
        sum += arr[i];
    }
    if(sum <= target) {//�����С��target���������е�Ԫ�ؾ�һ�������û�
        return arr[arrSize - 1];
    }
    for(i = target / arrSize; i <= (target / arrSize) + 3175; i++) {//i����߽���ƽ��ֵ���ұ߽������Գ�����
        temp = 0;
        for(j = 0; j < arrSize; j++) {//������С��i��Ԫ���������
            if(arr[j] <= i)
                temp += arr[j];
            else
                break;
        }
        temp = temp + i * (arrSize - j);//��������i��Ԫ��ȫ������i�ӽ�ȥ���
        if(abs(temp - target) < abs(sum - target)) {//�ж��ǲ��Ǳȵ�ǰ�Ѿ�������Ļ�ҪС
            sum = temp;
            res = i;
        }
    }
    return res;
}
