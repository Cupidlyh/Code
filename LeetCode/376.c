#include <stdio.h>
#include <stdlib.h>

int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize <= 1)//��������Ԫ�ص�����Ҳ�ǰڶ�����
        return numsSize;
    int up = 1, down = 1;//up����ǰһʱ��������down����ǰһʱ���½�
    for(int i = 0;i < numsSize - 1; i++) {//��������
        if(nums[i] - nums[i + 1] < 0)//�����ʱ��ֵ�Ǹ���
            up = down + 1;//���������ļ�һ���ڶ�����Ҫ������������֣�
        if(nums[i] - nums[i + 1] > 0)//�����ʱ��ֵ������
            down = up + 1;//�����½��ļ�һ���ڶ�����Ҫ������������֣�
    }
    return (up > down ? up : down);//�������ֵ
}
