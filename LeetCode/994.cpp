#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int>x,y;//�ö������洢�������ӵ�����
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//��������
        int i,j,row = grid.size(),col = grid[0].size();
        int time = -1,map[11][11] = {0};//time��¼���Ӷ����õķ�������mapΪ�������
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                if(grid[i][j] == 2) {//�ҵ���ʼ�����и��õ�����
                    map[i][j] = 1;//���
                    x.push(i);//���������
                    y.push(j);
                }
        x.push(-1);//�ڶ�������-1����ÿ���Ӹ��õ����ӷָ���
        y.push(-1);
        int xx,yy;
        while(!x.empty()) {//�����������
            xx = x.front();
            x.pop();
            yy = y.front();
            y.pop();
            if(xx == -1 && yy == -1) {//ȡ����Ԫ��Ϊ-1
                time++;//��������1
                if(!x.empty()) {//��������л��и�������
                    x.push(-1);
                    y.push(-1);
                }
                continue;
            }
            for(i = 0; i < 4; i++) {//���õ����ӻὫ���ڵ�4������������Ӹ��õ�
                int x1 = xx + coor[i][0];
                int y1 = yy + coor[i][1];
                if(x1 < 0 || y1 < 0 || x1 >= row || y1 >= col)//���������
                    continue;
                if(grid[x1][y1] == 1 && map[x1][y1] == 0) {//�������������������û������
                    map[x1][y1] = 1;//��Ǵ����ѱ�����
                    x.push(x1);//���������
                    y.push(y1);
                }
            }
        }
        int flag = 0;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                if(grid[i][j] == 1 && map[i][j] == 0) {//���±����������map���Ƿ������������
                    flag = 1;
                    break;
                }
        if(flag == 1)//������������
            return -1;//����-1
        return time;//���򷵻�����ȫ�����õ���С������
    }
};
