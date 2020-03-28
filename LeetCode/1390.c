#include <stdio.h>
#include <stdlib.h>

int getsum(int n) {
    int num = 2;//记录因数数量(1和本身肯定是因数)
    int sum = 1 + n;//记录因数和
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            if(num == 4) {//题目只要找四因数，多了就不符合题意
                num++;
                break;
            }
            sum += i;
            num++;
            if(n / i != i) {//相同因数只算一个
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
