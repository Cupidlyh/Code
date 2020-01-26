#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N,i,x1,x2,x3,x4,y1,y2,y3,y4;
    double k1,k2,b1,b2,x,y;
    scanf("%d",&N);
    printf("INTERSECTING LINES OUTPUT\n");
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(x1 != x2)//ֱ��һ������б�ʵ����
        {
            k1 = ((double)y2 - (double)y1) / (x2 - x1);//ֱ�߹�ʽ��y = k * x + b�����ֱ�ߵ�k��b
            b1 = y1 - k1 * x1;
        }
        if(x3 != x4)//ֱ�߶�������б�ʵ����
        {
            k2 = ((double)y4 - (double)y3) / (x4 - x3);
            b2 = y3 - k2 * x3;
        }
        //ֱ���غϵ����������һ������ֱ��k��b��һ������������ֱ�߶���б�ʲ�������ֱ�ߵ�xһ����x1����x3��
        if((k1 == k2 && b1 == b2) || (x1 == x2 && x3 == x4 && x1 == x3))
        {
            printf("LINE\n");
            continue;
        }
        //ֱ�߲��ཻҲ���غϾ���ƽ�У�ƽ�е����������һ��б����ͬ������ֱ�߶���б�ʵ�������ֱ�ߵ�x��һ����x1������x3��
        if(k1 == k2 || (x1 == x2 && x3 == x4))
        {
            printf("NONE\n");
            continue;
        }
        printf("POINT ");
        //����ֱ���н�������֮һ����һ���Ǵ�ֱ��x�ᣬһ����ֱ��y��
        if((x1 == x2 && y3 == y4))
        {
            printf("%d.00 %d.00\n",x1,y3);
            continue;
        }
        if((y1 == y2 && x3 == x4))
        {
            printf("%d.00 %d.00\n",x3,y1);
            continue;
        }
        //��һ������ǼȲ��غ�Ҳ���뽻Ҳ����������ֱ�߷ֱ�ֱ��x��y���y��x�ᣨ������һ�ֵ�ֱ���ཻ��������
        y = (b1 * k2 - b2 * k1) / (k2 - k1);
        x = (k2 * y - b1 * k2) / (k1 * k2);
        printf("%0.2f %0.2f\n",x,y);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
