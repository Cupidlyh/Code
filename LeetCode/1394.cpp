class Solution {
public:
    int findLucky(vector<int>& arr) {
        int map[505] = {0},i;//map��¼ÿ��Ԫ�س��ֵĴ���
        for(i = 0; i < arr.size(); i++)
            map[arr[i]]++;
        for(i = 500; i >= 1; i--)//��ĿҪ�󷵻�����һ��
            if(map[i] == i)
                return i;
        return -1;
    }
};
