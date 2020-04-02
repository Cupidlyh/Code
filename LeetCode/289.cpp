#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int coor[8][2] = {0,1,0,-1,-1,0,1,0,-1,1,1,1,-1,-1,1,-1};//上下左右，左上，右上，左下，右下
        int row = board.size(),col = board[0].size();
        int i,j,k;
        for(i = 0; i < row; i++) {//遍历面板每一个格子里的细胞
            for(j = 0; j < col; j++) {
                int live = 0;//对于每一个细胞统计其八个相邻位置里的活细胞数量
                for(k = 0; k < 8; k++) {
                    //相邻位置坐标
                    int xx = i + coor[k][0];
                    int yy = j + coor[k][1];
                    if(xx < 0 || yy < 0 || xx >= row || yy >= col)//越界
                        continue;
                    if(abs(board[xx][yy]) == 1)
                        live += 1;
                }
                if((board[i][j] == 1) && (live < 2 || live > 3))//规则1或规则3
                    board[i][j] = -1; //-1代表这个细胞过去是活的现在死了
                if(board[i][j] == 0 && live == 3)//规则4
                    board[i][j] = 2;//2代表这个细胞过去是死的现在活了
            }
        }
        for(i = 0; i < row; i++)//遍历 board 得到一次更新后的状态
            for(j = 0; j < col; j++)
                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
    }
};
