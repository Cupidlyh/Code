#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[6][3]= {{0,0,-1},{0,0,1},{-1,0,0},{1,0,0},{0,-1,0},{0,1,0}};//下一步怎么走（前二是列数变，中二是层数变，后二是行数变）
char map[35][35][35];//存地图
int vis[35][35][35];//标记地图中的点是否被走过
int flag,x,y,z;//x，y，z代表层数，行数，列数

struct node//队列
{
    int x,y,z;//x，y，z代表层数，行数，列数
    int num;//num代表步数
} que[30010];

void bfs(int sx,int sy,int sz)
{

    int head=0;//队列的头指针
    int tail=1;//队列的尾指针
    que[0].x=sx;
    que[0].y=sy;
    que[0].z=sz;
    que[0].num=0;
    vis[sx][sy][sz]=1;
    int xx,yy,zz;
    while(head<tail)//当对列不为空时
    {
        for(int i=0; i<6; i++)//下一步如何走（6种情况）
        {
            xx=que[head].x+dir[i][0];
            yy=que[head].y+dir[i][1];
            zz=que[head].z+dir[i][2];
            if(map[xx][yy][zz]=='E') //搜到终点
            {
                printf("Escaped in %d minute(s).\n",que[head].num+1);
                flag=1;
                break;
            }
            if(xx < x && yy < y && zz < z && xx >= 0 && yy >= 0 && zz >= 0 && vis[xx][yy][zz] == 0 && map[xx][yy][zz] == '.') //如果在迷宫内，并且未走过
            {
                que[tail].x=xx;
                que[tail].y=yy;
                que[tail].z=zz;
                que[tail].num=que[head].num+1;
                vis[xx][yy][zz]=1;
                tail++;
            }
        }
        if(flag == 1)//flag为1说明已经找到了终点
            break ;
        head++;//flag不为1，那就要在继续寻找
    }
    if(flag == 0)
        printf("Trapped!\n");
}

int main()
{
    while(scanf("%d %d %d",&x,&y,&z) != EOF)
    {
        getchar();//吸收回车
        if(x == 0 && y == 0 && z == 0)
            break;
        memset(vis,0,sizeof(vis));//标记数组置零
        flag = 0;
        int i,j,k,sx,sy,sz;
        for(i = 0; i < x; i++)
            for(j = 0; j < y; j++)
            {
                for(k = 0; k < z; k++)
                {
                    scanf("%c",&map[i][j][k]);//读入地图
                    if(map[i][j][k] == 'S')//找到起点的位置并记录下来
                    {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
                getchar();//吸收回车
                if(j == y - 1 && i != x - 1)
                    getchar();//吸收空行（也就是回车）
            }
        bfs(sx,sy,sz);//广度优先搜索
    }
    return 0;
}
