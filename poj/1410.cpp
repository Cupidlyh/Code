#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,xs,ys,xe,ye,xl,yl,xr,yr,temp;
    double k,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d %d %d %d %d",&xs,&ys,&xe,&ye,&xl,&yl,&xr,&yr);
        if(xl > xr)//���ε����������˳��һ�����ȸ������ٸ����£���Ҫ�Լ��ж�
        {
            temp = xl;
            xl = xr;
            xr = temp;
        }
        if(yl < yr)
        {
            temp = yl;
            yl = yr;
            yr = temp;
        }
        if(xs > xe)//���˹涨�߶������x����С���Ǹ���
        {
            temp = xs;
            xs = xe;
            xe = temp;
            temp = ys;
            ys = ye;
            ye = temp;
        }
        if((xs >= xl && xs <= xr) && (xe >= xl && xe <= xr) && (ys <= yl && ys >= yr) && (ye <= yl && ye >= yr))//�߶��ھ��ε��ڲ�
        {
            printf("T\n");
            continue;
        }
        if(xs == xe && (xs >= xl && xs <= xr))//�߶δ�ֱ��x��������±��ཻ
        {
            if(ys > ye && (ye <= yr && ys >= yr))
            {
                printf("T\n");
                continue;
            }
            if(ys < ye && (ys <= yr && ye >= yr))
            {
                printf("T\n");
                continue;
            }
        }
        if(xs == xe && (xs >= xl && xs <= xr))//�߶δ�ֱ��x��������ϱ��ཻ
        {
            if(ys > ye  && (ys >= yl && ys <= yl))
            {
                printf("T\n");
                continue;
            }
            if(ys < ye && (ye >= yl && ye <= yl))
            {
                printf("T\n");
                continue;
            }
        }
        if(ys == ye && (ys >= yr && ys <= yl))//�߶δ�ֱ��y�����������ཻ
        {
            if(xs <= xl && xe >= xl)
            {
                printf("T\n");
                continue;
            }
        }
        if(ys == ye && (ys >= yr && ys <= yl))//�߶δ�ֱ��y��������ұ��ཻ
        {
            if(xs <= xr && xe >= xl)
            {
                printf("T\n");
                continue;
            }
        }
        if(xs != xe && ys != ye)
        {
            k = ((double)ye - (double)ys) / (xe - xs);//�����߶ε�б��
            b = ys - k * xs;//ֱ�߹�ʽy = k * x + b�е�b
            if(((k * xl + b) >= yr && (k * xl + b) <= yl) && (xs <= xl && xe >= xl))//�߶�������ཻ
            {
                printf("T\n");
                continue;
            }
            if(((k * xr + b) >= yr && (k * xr + b) <= yl) && (xs <= xr && xe >= xr))//�߶����ұ��ཻ
            {
                printf("T\n");
                continue;
            }
            if((((yl - b) / k) >= xl && ((yl - b) / k) <= xr) && ((ys <= yl && ye >= yl) || (ye <= yl && ys >= yl)))//�߶����ϱ��ཻ
            {
                printf("T\n");
                continue;
            }
            if((((yr - b) / k) >= xl && ((yr - b) / k) <= xr) && ((ys <= yr && ye >= yr) || (ye <= yr && ys >= yr)))//�߶����±��ཻ
            {
                printf("T\n");
                continue;
            }
        }
        printf("F\n");
    }
    return 0;
}
