#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int num = 1,i = 0;//numΪ��ǰҪ�����С���ѵ��ǹ�����iΪС���ѵı��
        while(true) {
            if(candies > num) {//ʣ���ǹ�������Ҫ������ǹ�����candies����ʣ����ǹ�����
                candies = candies - num;
                res[i] = res[i] + num;
                num++;
                i++;
            }
            else {//ʣ���ǹ�������
                res[i] = res[i] + candies;
                break;
            }
            if(i == num_people)//������´ӵ�һ��С���ѿ�ʼ���ǣ���һ��С���ѱ��Ϊ0��
                i = 0;
        }
        return res;
    }
};
