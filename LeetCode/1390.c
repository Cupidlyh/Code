#include <stdio.h>
#include <stdlib.h>

int getsum(int n) {
    int num = 2;//��¼��������(1�ͱ���϶�������)
    int sum = 1 + n;//��¼������
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            if(num == 4) {//��ĿֻҪ�������������˾Ͳ���������
                num++;
                break;
            }
            sum += i;
            num++;
            if(n / i != i) {//��ͬ����ֻ��һ��
                sum += n / i;
                num++;
            }
        }
    }
    if(num == 4)
        return sum;
    return 0;
}

int sumFourDivisors(int* nums, int numsSize){
    int res = 0;
    for(int i = 0; i < numsSize; i++)
        res += getsum(nums[i]);
    return res;
}
