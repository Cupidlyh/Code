#include <iostream>

using namespace std;

class Solution {
    int res;//������Ϳɫ��res�ľ���ֵ���ǵ�����ܸ�����
    int max = 0;//��¼���ĵ������
    int num;//��¼ÿһ����������
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//��������
    void bfs(vector<vector<int>>& grid,int row,int col) {//����Ĺ��������������Ŀ���������������
        queue<int>x;
        queue<int>y;
        x.push(row);
        y.push(col);
        num++;//ÿѹ������һ��Ԫ�ص�������ͼ�1
        while(!x.empty()) {
            int tx,ty,nx,ny;
            tx = x.front();
            ty = y.front();
            x.pop();
            y.pop();
            for(int i = 0; i < 4; i++) {//������������Ѱ��
                nx = tx + coor[i][0];
                ny = ty + coor[i][1];
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())//Խ��
                    continue;
                if(grid[nx][ny] == 1) {//�ҵ����ڵ�����
                    grid[nx][ny] = res;
                    x.push(nx);
                    y.push(ny);
                    num++;
                }
            }
        }
        max = max > num ? max : num;//��¼���ĵ������
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res = 0;
        int i,j;
        for(i = 0; i < grid.size(); i++) {
            for(j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    num = 0;//������¿�ʼ����
                    grid[i][j] = --res;//����Ϳɫ
                    bfs(grid,i,j);
                }
            }
        }
        return max;//����������
    }
};
