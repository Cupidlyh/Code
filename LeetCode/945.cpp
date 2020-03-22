#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        //mapͳ��A������Ԫ�س��ֵĸ�������ΪA���ܸ���40000��39999������mapҪ����80000
        int map[80000] = {0};
        int i,j,res = 0;
        for(i = 0; i < A.size(); i++)//ͳ��A����Ԫ�س��ֵĸ���
            map[A[i]]++;
        for(i = 0; i < 80000; i++) {
            if(map[i] <= 1)//Ԫ�س��ִ���С�ڵ���1Ҫ��������Ϊ���е�������������
                continue;
            while(map[i] > 1) {//ÿ��Ԫ�����ֻ����һ�Σ�ѭ����ֹ������
                map[i]--;
                for(j = i + 1; j < 80000; j++)//�ڴ�Ԫ��֮��Ѱ�ҵ�һ��û���ֹ���Ԫ��
                    if(map[j] == 0) {
                        map[j] = 1;//���
                        res += j - i;//��Ӳ���������ÿ����һ������1��
                        break;
                    }
            }
        }
        return res;
    }
};
