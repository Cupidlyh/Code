#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int num = 1,i = 0;//num为当前要分配给小朋友的糖果数，i为小朋友的编号
        while(true) {
            if(candies > num) {//剩余糖果数大于要分配的糖果数（candies代表剩余的糖果数）
                candies = candies - num;
                res[i] = res[i] + num;
                num++;
                i++;
            }
            else {//剩余糖果数不足
                res[i] = res[i] + candies;
                break;
            }
            if(i == num_people)//编号重新从第一个小朋友开始分糖（第一个小朋友编号为0）
                i = 0;
        }
        return res;
    }
};
