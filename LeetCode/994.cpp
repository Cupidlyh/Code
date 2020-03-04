#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int>x,y;//用队列来存储腐烂橘子的坐标
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        int i,j,row = grid.size(),col = grid[0].size();
        int time = -1,map[11][11] = {0};//time记录橘子都腐烂的分钟数，map为标记数组
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                if(grid[i][j] == 2) {//找到初始数组中腐烂的橘子
                    map[i][j] = 1;//标记
                    x.push(i);//存进队列中
                    y.push(j);
                }
        x.push(-1);//在队列中用-1来将每分钟腐烂的橘子分隔开
        y.push(-1);
        int xx,yy;
        while(!x.empty()) {//广度优先搜索
            xx = x.front();
            x.pop();
            yy = y.front();
            y.pop();
            if(xx == -1 && yy == -1) {//取出的元素为-1
                time++;//分钟数加1
                if(!x.empty()) {//如果队列中还有腐烂橘子
                    x.push(-1);
                    y.push(-1);
                }
                continue;
            }
            for(i = 0; i < 4; i++) {//腐烂的橘子会将相邻的4个正方向的橘子腐烂掉
                int x1 = xx + coor[i][0];
                int y1 = yy + coor[i][1];
                if(x1 < 0 || y1 < 0 || x1 >= row || y1 >= col)//错误的坐标
                    continue;
                if(grid[x1][y1] == 1 && map[x1][y1] == 0) {//如果遍历到新鲜橘子且没被腐烂
                    map[x1][y1] = 1;//标记代表已被腐烂
                    x.push(x1);//存进队列中
                    y.push(y1);
                }
            }
        }
        int flag = 0;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                if(grid[i][j] == 1 && map[i][j] == 0) {//重新遍历标记数组map看是否存在新鲜橘子
                    flag = 1;
                    break;
                }
        if(flag == 1)//存在新鲜橘子
            return -1;//返回-1
        return time;//否则返回橘子全部腐烂的最小分钟数
    }
};
