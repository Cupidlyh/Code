#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int arr[10005] = {0};//�����洢�������ֵ�ÿһλ����
        int sum = 0,bit = log10(num) + 1,i,j = 0;
        for(i = bit - 1; i >= 0; i--) {//�����ֵ�ÿһλ�𿪴浽������
            arr[i] = num % 10;
            num = num / 10;
        }
        for(i = 0; i <= bit - 1; i++) {//�����λ��ʼ��
            if(arr[i] == 6) {//�ҵ��ĵ�һ��6�������9
                arr[i] = 9;
                break;
            }
        }
        for(i = bit - 1; i >= 0; i--) {//������ĺ�����ֺ�
            sum = sum + arr[i] * ((int)(pow(10,j++) + 0.5));
        }
        return sum;
    }
};
