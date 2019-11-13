#include <stdio.h>
#include <stdlib.h>

int map[105][105];//地图
int next[8][2]= {-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};//下一步如何走（上下左右，左上，右上，左下，右下）
int m,n;

void dfs(int x,int y,int color)
{
    int k,xx,yy;
    map[x][y] = color;//地图中油藏标记成不同的数字（代表不同的油藏区域）
    for(k = 0; k <= 7; k++)//下一步可能走到的位置
    {
        xx = x + next[k][0];
        yy = y + next[k][1];
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && map[xx][yy] == 1)//如果是油藏且在地图范围内
        {
            dfs(xx,yy,color);//继续深度优先遍历
        }
    }
}

int main()
{
    while(scanf("%d %d",&m,&n) != EOF)
    {
        getchar();//吸收回车
        if(m == 0)
            break;
        int i,j;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                char temp;
                scanf("%c",&temp);//读入地图
                if(temp == '@')//将地图转成整型存储
                    map[i][j] = 1;//1代表油藏
                if(temp == '*')
                    map[i][j] = 0;//0代表无油
            }
            getchar();//吸收回车
        }
        int num = 0;//num记录油藏数量
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(map[i][j] == 1)//遍历数组找到油藏的位置
                {
                    num--;
                    dfs(i,j,num);//深度优先遍历
                }
        printf("%d\n",-num);
    }
    return 0;
}
