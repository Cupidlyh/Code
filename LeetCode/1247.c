#include <stdio.h>
#include <stdlib.h>

int minimumSwap(char * s1, char * s2){
    //x������¼s1��s2��x���ֵ�������yͬ��  map�������s1��s2����Ԫ�ز���ͬ
    int x = 0, y = 0, len = strlen(s1), i, map[1001] = {0};
    for(i = 0; i < len; i++) {//�ȱ���һ��s1��s2����
        if(s1[i] == 'x')
            x++;
        if(s1[i] == 'y')
            y++;
        if(s2[i] == 'x')
            x++;
        if(s2[i] == 'y')
            y++;
        if(s1[i] != s2[i])//��s1��s2Ԫ�ز�ͬʱ
            map[i] = 1;//���
    }
    if(x % 2 != 0 || y % 2 != 0)//��x����y����һ��������ʱ
        return -1;//û�취ʹ�����ַ������
    int j = 0;
    char s11[1001] = {'0'};//���s1��s2��ͬ����s1��Ԫ��
    for(i = 0; i < len; i++) {
        if(map[i] == 1) {//����ǵ��ǲ�ͬ��
            s11[j++] = s1[i];//���ȥ
        }
    }
    x = 0;
    y = 0;
    int num = 0;//num�Ǽ�¼��������
    for(i = 0; i < j; i++) {//ͳ��s11������x��y���ֵĴ���
        if(s11[i] == 'x') {
            x++;
        }
        if(s11[i] == 'y')
            y++;
    }
    int flag = 0;//��Ǳ���

    //ʣ�µľ��Ǵ���Ĺ��ɣ����ַ���"xx"��"yy"ʱ���ǽ���һ�Σ����ַ���"xy"��"yx"ʱ���ǽ�������
    //x��y��ż��������ʱ�ͷֱ���������������    ���������ε����ֻ����һ�Σ�
    if(x % 2 == 0)//�ж�x����ż��
        num = num + x / 2;
    else {
        flag = 1;
        num = num + (x - 1) / 2;
    }
    if(y % 2 == 0)//�ж�y����ż��
        num = num + y / 2;
    else {
        flag = 1;
        num = num + (y - 1) / 2;
    }
    if(flag == 1)//���x��y������ʱ
        num = num + 2;//��������
    return num;
}
