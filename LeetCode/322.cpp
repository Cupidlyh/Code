#include <iostream>

using namespace std;

class Solution {
    int min = INT_MAX;//������¼����Ӳ����
public:
    void dfs(vector<int>& coins, long long am,int index,int num) {//am�ǵ�ǰʣ�µ�Ǯ��index�������±꣬num�ǵ�ǰ���õ�Ӳ����
        if(am == 0) {//�ҵ�һ���ʹ��Ǯ�չ���
            min = min > num ? num : min;//ͨ���Ƚϵõ�Ӳ�����ٵĽ�
            return ;
        }
        if(index == -1)//�±�-1��Ҫ������
            return ;
        for(int k = am / coins[index]; k >= 0; k--) {//ֱ����ʣ�µ�Ǯ���ü��ŵ�ǰ�����Ǯ��Ȼ�����
            if(num + k >= min)//�����ǰ��Ӳ�������Ͻ������õ�Ӳ���������Ѵչ���ĳ��Ӳ����
                return ;//ֱ�ӷ���
            dfs(coins,am - k * coins[index],index - 1,num + k);
        }
        return ;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());//��Ӳ�Ұ�����ֵ��С��������
        dfs(coins,amount,coins.size() - 1,0);//������������Ӽ�֦
        if(min != INT_MAX)
            return min;
        return -1;
    }
};
