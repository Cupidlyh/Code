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
        int coor[8][2] = {0,1,0,-1,-1,0,1,0,-1,1,1,1,-1,-1,1,-1};//�������ң����ϣ����ϣ����£�����
        int row = board.size(),col = board[0].size();
        int i,j,k;
        for(i = 0; i < row; i++) {//�������ÿһ���������ϸ��
            for(j = 0; j < col; j++) {
                int live = 0;//����ÿһ��ϸ��ͳ����˸�����λ����Ļ�ϸ������
                for(k = 0; k < 8; k++) {
                    //����λ������
                    int xx = i + coor[k][0];
                    int yy = j + coor[k][1];
                    if(xx < 0 || yy < 0 || xx >= row || yy >= col)//Խ��
                        continue;
                    if(abs(board[xx][yy]) == 1)
                        live += 1;
                }
                if((board[i][j] == 1) && (live < 2 || live > 3))//����1�����3
                    board[i][j] = -1; //-1�������ϸ����ȥ�ǻ����������
                if(board[i][j] == 0 && live == 3)//����4
                    board[i][j] = 2;//2�������ϸ����ȥ���������ڻ���
            }
        }
        for(i = 0; i < row; i++)//���� board �õ�һ�θ��º��״̬
            for(j = 0; j < col; j++)
                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
    }
};
