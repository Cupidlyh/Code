class Solution {
public:
    int findLucky(vector<int>& arr) {
        int map[505] = {0},i;//map记录每个元素出现的次数
        for(i = 0; i < arr.size(); i++)
            map[arr[i]]++;
        for(i = 500; i >= 1; i--)//题目要求返回最大的一个
            if(map[i] == i)
                return i;
        return -1;
    }
};
