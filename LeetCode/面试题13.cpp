class Solution {
public:
    int arr[102][102];//存储横纵坐标数位之和

    int SumOfDigit(int i,int j) {//求行坐标和纵坐标的数位之和
        int sum = 0;;//总和
        while(i) {
            sum += i % 10;
            i /= 10;
        }
        while(j) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }

    int BFS(int m,int n,int k,int i,int j) {//广度优先搜索
        int res = 0;
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        int book[102][102] = {0};//标记数组
        queue<int>x;
        queue<int>y;
        x.push(i);
        y.push(j);
        book[i][j] = 1;
        while(!x.empty()) {
            res++;
            int x1 = x.front();
            int y1 = y.front();
            x.pop();
            y.pop();
            for(int w = 0; w < 4; w++) {
                int xx = x1 + coor[w][0];
                int yy = y1 + coor[w][1];
                if(xx >= m || yy >= n || xx < 0 || yy < 0)//越界
                    continue;
                if(book[xx][yy] == 1 || arr[xx][yy] > k)//已经走过或不能到达
                    continue;
                book[xx][yy] = 1;
                x.push(xx);
                y.push(yy);
            }
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        int i,j;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                arr[i][j] = SumOfDigit(i,j);
        return BFS(m,n,k,0,0);
    }
};
