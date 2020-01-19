#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int arr[10005] = {0};//用来存储给定数字的每一位数字
        int sum = 0,bit = log10(num) + 1,i,j = 0;
        for(i = bit - 1; i >= 0; i--) {//将数字的每一位拆开存到数组中
            arr[i] = num % 10;
            num = num / 10;
        }
        for(i = 0; i <= bit - 1; i++) {//从最高位开始找
            if(arr[i] == 6) {//找到的第一个6将它变成9
                arr[i] = 9;
                break;
            }
        }
        for(i = bit - 1; i >= 0; i--) {//算出更改后的数字和
            sum = sum + arr[i] * ((int)(pow(10,j++) + 0.5));
        }
        return sum;
    }
};
