#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dir[6][3]= {{0,0,-1},{0,0,1},{-1,0,0},{1,0,0},{0,-1,0},{0,1,0}};//��һ����ô�ߣ�ǰ���������䣬�ж��ǲ����䣬����������䣩
char map[35][35][35];//���ͼ
int vis[35][35][35];//��ǵ�ͼ�еĵ��Ƿ��߹�
int flag,x,y,z;//x��y��z�������������������

struct node//����
{
    int x,y,z;//x��y��z�������������������
    int num;//num������
} que[30010];

void bfs(int sx,int sy,int sz)
{

    int head=0;//���е�ͷָ��
    int tail=1;//���е�βָ��
    que[0].x=sx;
    que[0].y=sy;
    que[0].z=sz;
    que[0].num=0;
    vis[sx][sy][sz]=1;
    int xx,yy,zz;
    while(head<tail)//�����в�Ϊ��ʱ
    {
        for(int i=0; i<6; i++)//��һ������ߣ�6�������
        {
            xx=que[head].x+dir[i][0];
            yy=que[head].y+dir[i][1];
            zz=que[head].z+dir[i][2];
            if(map[xx][yy][zz]=='E') //�ѵ��յ�
            {
                printf("Escaped in %d minute(s).\n",que[head].num+1);
                flag=1;
                break;
            }
            if(xx < x && yy < y && zz < z && xx >= 0 && yy >= 0 && zz >= 0 && vis[xx][yy][zz] == 0 && map[xx][yy][zz] == '.') //������Թ��ڣ�����δ�߹�
            {
                que[tail].x=xx;
                que[tail].y=yy;
                que[tail].z=zz;
                que[tail].num=que[head].num+1;
                vis[xx][yy][zz]=1;
                tail++;
            }
        }
        if(flag == 1)//flagΪ1˵���Ѿ��ҵ����յ�
            break ;
        head++;//flag��Ϊ1���Ǿ�Ҫ�ڼ���Ѱ��
    }
    if(flag == 0)
        printf("Trapped!\n");
}

int main()
{
    while(scanf("%d %d %d",&x,&y,&z) != EOF)
    {
        getchar();//���ջس�
        if(x == 0 && y == 0 && z == 0)
            break;
        memset(vis,0,sizeof(vis));//�����������
        flag = 0;
        int i,j,k,sx,sy,sz;
        for(i = 0; i < x; i++)
            for(j = 0; j < y; j++)
            {
                for(k = 0; k < z; k++)
                {
                    scanf("%c",&map[i][j][k]);//�����ͼ
                    if(map[i][j][k] == 'S')//�ҵ�����λ�ò���¼����
                    {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
                getchar();//���ջس�
                if(j == y - 1 && i != x - 1)
                    getchar();//���տ��У�Ҳ���ǻس���
            }
        bfs(sx,sy,sz);//�����������
    }
    return 0;
}
