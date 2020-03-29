#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int map[105][105];//标记数组
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    struct ss {//存储坐标和步数
        int x,y,step;
    };

    int findmin(vector<vector<int>>& grid,int i,int j) {//广度优先搜索找离当前海最近的陆地
        int k,xx,yy;
        map[i][j] = 1;
        queue<ss>q;
        q.push({i,j,0});
        while(!q.empty()) {
            struct ss s = q.front();
            q.pop();
            for(k = 0; k < 4; k++) {
                xx = s.x + coor[k][0];
                yy = s.y + coor[k][1];
                if(xx < 0 || yy < 0 || xx >= grid.size() || yy >= grid[0].size())//越界条件
                    continue;
                if(grid[xx][yy] == 1 && map[xx][yy] == 0)
                    return s.step + 1;
                if(grid[xx][yy] == 0 && map[xx][yy] == 0) {
                    map[xx][yy] = 1;
                    q.push({xx,yy,s.step + 1});
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int res = -1,i,j;
        for(i = 0; i < grid.size(); i++) {
            for(j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    memset(map,0,sizeof(map));
                    res = max(res,findmin(grid,i,j));//二者取较大的那一个
                }
            }
        }
        return res;
    }
};
