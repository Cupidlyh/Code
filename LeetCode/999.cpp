#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0,i,j,flag = 0;
        for(i = 0; i < board.size(); i++) {//先找到白车的位置
            for(j = 0; j < board[0].size(); j++)
                if(board[i][j] == 'R') {
                    flag = 1;
                    break;
                }
            if(flag == 1)
                break;
        }
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        int xx,yy;
        for(int k = 0; k < 4; k++) {
            xx = i + coor[k][0];
            yy = j + coor[k][1];
            flag = 0;
            while(xx >= 0 && yy >= 0 && xx < board.size() && yy < board[0].size()) {//车先一直朝一个方向走直到碰见边界
                if(board[xx][yy] == 'p') {//遇见黑卒代表可以捕获
                    flag = 1;
                    break;
                }
                if(board[xx][yy] == 'B')//遇见白象代表此方向不能走了
                    break;
                xx = xx + coor[k][0];
                yy = yy + coor[k][1];
            }
            if(flag == 1)//如果flag被标记代表此方向在遇见白象或走到边界前有黑卒让我捕获
                res++;//结果加1
        }
        return res;
    }
};
