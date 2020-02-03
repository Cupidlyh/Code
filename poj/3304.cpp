#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int m;
const double n = 1e-8;

struct segment//�洢�߶εĶ˵�����
{
    double x1,y1,x2,y2;
} s[110];

double dis(double x1,double y1,double x2,double y2)//�����ľ���
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double cross(double a,double b,double c,double d,double e,double f)//����������ж�ֱ�����߶��Ƿ��ཻ
{
    return (a - c) * (b - f) - (a - e) * (b - d);
}

bool judge(double x1,double y1,double x2,double y2)
{
    if(dis(x1,y1,x2,y2) < n)//�����ͬһ����
        return false;
    for(int i = 0; i < m; i++)//��������ֱ��Ҫ�������߶��ཻ
        if(cross(x1,y1,x2,y2,s[i].x1,s[i].y1) * cross(x1,y1,x2,y2,s[i].x2,s[i].y2) > 0)
            return false;
    return true;
}

int main()
{
    int T,flag;
    scanf("%d",&T);
    while(T--)
    {
        int i,j;
        scanf("%d",&m);
        for(i = 0; i < m; i++)
            scanf("%lf %lf %lf %lf",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
        if(m == 1)//ֻ��һ���߶�һ������
        {
            printf("Yes!\n");
            continue;
        }
        flag = 0;
        for(i = 0; i < m; i++)//ö�ٳ������ж˵㹹�ɵ�ֱ��
        {
            for(j = i + 1; j < m; j++)
            {
                if(judge(s[i].x1,s[i].y1,s[j].x1,s[j].y1)||
                   judge(s[i].x1,s[i].y1,s[j].x2,s[j].y2)||
                   judge(s[i].x2,s[i].y2,s[j].x1,s[j].y1)||
                   judge(s[i].x2,s[i].y2,s[j].x2,s[j].y2))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(flag == 1)
            printf("Yes!\n");
        else
            printf("No!\n");
    }
    return 0;
}
