class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        int oldColor = image[sr][sc];
        if(newColor == oldColor)
            return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        //广度优先搜索
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            image[r][c] = newColor;
            for(int i = 0; i < 4; i++) {
                int xx = r + coor[i][0];
                int yy = c + coor[i][1];
                //越界
                if(xx < 0 || yy < 0 || xx >= image.size() || yy >= image[0].size())
                    continue;
                if(image[xx][yy] == oldColor)
                    q.push({xx,yy});
            }
        }
        return image;
    }
};
