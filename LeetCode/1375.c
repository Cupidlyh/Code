#include <stdio.h>
#include <stdlib.h>

int numTimesAllBlue(int* light, int lightSize){
    int max = 0,num = 0,i;
    for(i = 0; i < lightSize; i++) {
        max = max > light[i] ? max : light[i];
        if(max == i + 1)//�����ǰ����������ĵƵ��ڱ������ĵƵ���������ô˵��ǰ��ĵƶ�����
            num++;//�������1
    }
    return num;
}
