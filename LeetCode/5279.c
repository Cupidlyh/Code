#include <stdio.h>
#include <stdlib.h>


int subtractProductAndSum(int n){
    long long int mul = 1,sum = 0;//mulΪÿһλ��˵Ľ����sumΪÿһλ��ӵĽ��
    int i,len = log10(n) + 1,temp;
    for(i = 0; i < len; i++) {//lenΪ���ֵ�λ��
        temp = n % 10;//�����ǰλ������
        mul *= temp;
        sum += temp;
        n = n / 10;
    }
    return mul - sum;
}


