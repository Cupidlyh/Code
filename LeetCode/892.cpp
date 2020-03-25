#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0)//��ǰλ��û��������ֱ������
                    continue;
                if(i == 0) {//��0�е�������ӵ�1�п�ʼ��������ڵĻ����ص�����
                    if(j == 0) {
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//�������ǰλ������������ı����
                    }
                    else {
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//�������ǰλ������������ı����
                        res = res - min(grid[i][j],grid[i][j - 1]) * 2;//��ȥ����������ص������
                    }
                }
                else {
                    if(j == 0) {//��һ�п�ʼ��ÿһ�еĵ�0�����ϱ����ڵĻ����ص�����
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//�������ǰλ������������ı����
                        res = res - min(grid[i][j],grid[i - 1][j]) * 2;//��ȥ���ϱ������ص������
                    }
                    else {//��һ�п�ʼ��ÿһ�г���0��������ж�������ߣ��ϱ����ڵĻ����ص�����
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//�������ǰλ������������ı����
                        res = res - min(grid[i][j],grid[i - 1][j]) * 2;//��ȥ���ϱ������ص������
                        res = res - min(grid[i][j],grid[i][j - 1]) * 2;//��ȥ����������ص������
                    }
                }
            }
        }
        return res;
    }
};
