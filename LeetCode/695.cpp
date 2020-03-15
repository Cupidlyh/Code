#include <iostream>

using namespace std;

class Solution {
    int res;//给岛屿涂色（res的绝对值就是岛屿的总个数）
    int max = 0;//记录最大的岛屿面积
    int num;//记录每一个岛屿的面积
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    void bfs(vector<vector<int>>& grid,int row,int col) {//经典的广度优先搜索的题目，借助队列来解决
        queue<int>x;
        queue<int>y;
        x.push(row);
        y.push(col);
        num++;//每压进队列一个元素岛屿面积就加1
        while(!x.empty()) {
            int tx,ty,nx,ny;
            tx = x.front();
            ty = y.front();
            x.pop();
            y.pop();
            for(int i = 0; i < 4; i++) {//上下左右依次寻找
                nx = tx + coor[i][0];
                ny = ty + coor[i][1];
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())//越界
                    continue;
                if(grid[nx][ny] == 1) {//找到相邻的土地
                    grid[nx][ny] = res;
                    x.push(nx);
                    y.push(ny);
                    num++;
                }
            }
        }
        max = max > num ? max : num;//记录最大的岛屿面积
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res = 0;
        int i,j;
        for(i = 0; i < grid.size(); i++) {
            for(j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    num = 0;//面积重新开始计算
                    grid[i][j] = --res;//岛屿涂色
                    bfs(grid,i,j);
                }
            }
        }
        return max;//返回最大面积
    }
};
