#include <stdio.h>
#include <stdlib.h>

int jump(int* nums, int numsSize){
    int pos = numsSize - 1,step = 0; //posΪҪ�ҵ�λ��
    while (pos > 0) { //�Ƿ��˵� 0 ��λ��
        for (int i = 0; i < pos; i++) {
            if (nums[i] + i >= pos) {
                pos = i; //����Ҫ�ҵ�λ��
                step++;
                break;
            }
        }
    }
    return step;
}
