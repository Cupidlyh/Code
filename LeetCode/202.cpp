#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);//��n���б��
        while(true) {
            int m = 0;
            while(n != 0) {//����ƽ����
                m += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = m;
            if(n == 1)//���Ϊ1��Ϊ������
                return true;
            if(s.find(n) != s.end())//��������Ѿ�����ǹ��ˣ���ζ����������ѭ�����Ͳ��ǿ�����
                break;
            s.insert(n);//���n
        }
        return false;
    }
};
