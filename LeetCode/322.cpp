#include <iostream>

using namespace std;

class Solution {
    int min = INT_MAX;//用来记录最少硬币数
public:
    void dfs(vector<int>& coins, long long am,int index,int num) {//am是当前剩下的钱，index是数组下标，num是当前已用的硬币数
        if(am == 0) {//找到一组解使得钱凑够了
            min = min > num ? num : min;//通过比较得到硬币最少的解
            return ;
        }
        if(index == -1)//下标-1就要返回了
            return ;
        for(int k = am / coins[index]; k >= 0; k--) {//直接算剩下的钱能用几张当前数组的钱凑然后遍历
            if(num + k >= min)//如果当前的硬币数加上接下来用的硬币数超过已凑够的某种硬币数
                return ;//直接返回
            dfs(coins,am - k * coins[index],index - 1,num + k);
        }
        return ;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());//将硬币按照面值从小到大排序
        dfs(coins,amount,coins.size() - 1,0);//深度优先搜索加剪枝
        if(min != INT_MAX)
            return min;
        return -1;
    }
};
