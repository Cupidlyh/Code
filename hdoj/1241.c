#include <stdio.h>
#include <stdlib.h>

int map[105][105];//��ͼ
int next[8][2]= {-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};//��һ������ߣ��������ң����ϣ����ϣ����£����£�
int m,n;

void dfs(int x,int y,int color)
{
    int k,xx,yy;
    map[x][y] = color;//��ͼ���Ͳر�ǳɲ�ͬ�����֣�����ͬ���Ͳ�����
    for(k = 0; k <= 7; k++)//��һ�������ߵ���λ��
    {
        xx = x + next[k][0];
        yy = y + next[k][1];
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && map[xx][yy] == 1)//������Ͳ����ڵ�ͼ��Χ��
        {
            dfs(xx,yy,color);//����������ȱ���
        }
    }
}

int main()
{
    while(scanf("%d %d",&m,&n) != EOF)
    {
        getchar();//���ջس�
        if(m == 0)
            break;
        int i,j;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                char temp;
                scanf("%c",&temp);//�����ͼ
                if(temp == '@')//����ͼת�����ʹ洢
                    map[i][j] = 1;//1�����Ͳ�
                if(temp == '*')
                    map[i][j] = 0;//0��������
            }
            getchar();//���ջس�
        }
        int num = 0;//num��¼�Ͳ�����
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(map[i][j] == 1)//���������ҵ��Ͳص�λ��
                {
                    num--;
                    dfs(i,j,num);//������ȱ���
                }
        printf("%d\n",-num);
    }
    return 0;
}
