#include <iostream>

using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int i=1,ans,j=n,num;
        while(i<=j){//whileѭ������Ƕ��ֲ����㷨
            num=i+(j-i)/2;
            if(guess(num)==0){//�ж������Ƿ����
                ans=num;//���˵���ҵ���
                break;
            }
            if(guess(num)==-1)//����µ�̫���ˣ���С�ұ߽�
                j=num-1;
            if(guess(num)==1)//����µ�̫С�ˣ���С��߽�
                i=num+1;
        }
        return ans;
};
};
