class Solution {
public:
    int coor[8][2] = {0,1,0,-1,-1,0,1,0,-1,1,1,1,-1,-1,1,-1};//上下左右，左上，右上，左下，右下

    //计算坐标[r,c]这点周围的地雷数目
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

    //深度优先搜索所有未挖出的方块
    void dfs(vector<vector<char>>& board,int r,int c) {
        int numsMines = numMines(board,r,c);
        //如果此未挖出的方块周围无地雷就继续深搜
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
        //如果此未挖出的方块周围有地雷就停止深搜
        else {
            board[r][c] = numsMines + '0';
        }
        return ;
    }


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //如果直接点到地雷游戏结束
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board,click[0],click[1]);
        return board;
    }
};
