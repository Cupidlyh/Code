#include <iostream>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0,i;
        for(i = 0; i < A.size(); i++)//�������е�Ԫ�����
            sum = sum + A[i];
        if(sum % 3 != 0)//�Ͳ��ܱ�3����
            return false;//���ֳܷɺ���ȵ�������
        int sum1 = 0,num = 0;
        for(i = 0; i < A.size(); i++) {
            sum1 += A[i];
            if(sum1 == sum / 3) {//sum / 3 ����������ÿһ���ֵĺ�
                sum1 = 0;//�͹���
                num++;//��¼�����˼����ֺ�Ϊsum/3
            }
            if(num == 2)//��������������
                break;
        }
        if(i < A.size() - 1)
            return true;
        return false;
    }
};
