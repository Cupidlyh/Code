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
        for(i = 0; i < board.size(); i++) {//���ҵ��׳���λ��
            for(j = 0; j < board[0].size(); j++)
                if(board[i][j] == 'R') {
                    flag = 1;
                    break;
                }
            if(flag == 1)
                break;
        }
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//��������
        int xx,yy;
        for(int k = 0; k < 4; k++) {
            xx = i + coor[k][0];
            yy = j + coor[k][1];
            flag = 0;
            while(xx >= 0 && yy >= 0 && xx < board.size() && yy < board[0].size()) {//����һֱ��һ��������ֱ�������߽�
                if(board[xx][yy] == 'p') {//�������������Բ���
                    flag = 1;
                    break;
                }
                if(board[xx][yy] == 'B')//�����������˷���������
                    break;
                xx = xx + coor[k][0];
                yy = yy + coor[k][1];
            }
            if(flag == 1)//���flag����Ǵ���˷���������������ߵ��߽�ǰ�к������Ҳ���
                res++;//�����1
        }
        return res;
    }
};
