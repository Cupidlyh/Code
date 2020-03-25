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
                if(grid[i][j] == 0)//当前位置没有立方体直接跳过
                    continue;
                if(i == 0) {//第0行的正方体从第1列开始与左边相邻的会有重叠的面
                    if(j == 0) {
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//计算出当前位置所有立方体的表面积
                    }
                    else {
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//计算出当前位置所有立方体的表面积
                        res = res - min(grid[i][j],grid[i][j - 1]) * 2;//减去与左边相邻重叠的面积
                    }
                }
                else {
                    if(j == 0) {//第一行开始的每一行的第0列与上边相邻的会有重叠的面
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//计算出当前位置所有立方体的表面积
                        res = res - min(grid[i][j],grid[i - 1][j]) * 2;//减去与上边相临重叠的面积
                    }
                    else {//第一行开始的每一行除第0列以外的列都会与左边，上边相邻的会有重叠的面
                        res = res + grid[i][j] * 6 - 2 * (grid[i][j] - 1);//计算出当前位置所有立方体的表面积
                        res = res - min(grid[i][j],grid[i - 1][j]) * 2;//减去与上边相临重叠的面积
                        res = res - min(grid[i][j],grid[i][j - 1]) * 2;//减去与左边相邻重叠的面积
                    }
                }
            }
        }
        return res;
    }
};
