class Solution {
public:
    int coor[8][2] = {0,1,0,-1,-1,0,1,0,-1,1,1,1,-1,-1,1,-1};//�������ң����ϣ����ϣ����£�����

    //��������[r,c]�����Χ�ĵ�����Ŀ
    int numMines(vector<vector<char>>& board,int r,int c) {
        int num = 0;
        for (int i = 0; i < 8; i++) {
            int xx = r + coor[i][0];
            int yy = c + coor[i][1];
            if (xx < 0 || yy < 0 || xx >= board.size() || yy >= board[0].size()) {
                continue;
            }
            if (board[xx][yy] == 'M')
                num++;
        }
        return num;
    }

    //���������������δ�ڳ��ķ���
    void dfs(vector<vector<char>>& board,int r,int c) {
        int numsMines = numMines(board,r,c);
        //�����δ�ڳ��ķ�����Χ�޵��׾ͼ�������
        if (numsMines == 0) {
            board[r][c] = 'B';
            for (int i = 0; i < 8; i++) {
                int xx = r + coor[i][0];
                int yy = c + coor[i][1];
                if (xx < 0 || yy < 0 || xx >= board.size() || yy >= board[0].size()) {
                    continue;
                }
                if (board[xx][yy] == 'E')
                    dfs(board,xx,yy);
            }
        }
        //�����δ�ڳ��ķ�����Χ�е��׾�ֹͣ����
        else {
            board[r][c] = numsMines + '0';
        }
        return ;
    }


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //���ֱ�ӵ㵽������Ϸ����
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board,click[0],click[1]);
        return board;
    }
};
