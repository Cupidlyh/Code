#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int cmp(const void *a,const void *b)
{
    const double p1 = *(const double*)a;
    const double p2 = *(const double*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}

int main()
{
    int n,d,x,y;
    int num = 0;
    while(scanf("%d %d",&n,&d) != EOF)
    {
        if(n == 0 && d == 0)
            break;
        int flag = 0;
        num++;
        int i,res = -1;
        double coor[1005][2],xx;
        //�Ե���ΪԲ�ģ�dΪ�뾶��Բ�������x�����������
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&x,&y);
            if(y > d)
                flag = 1;
            xx = sqrt(d * d - y * y);
            coor[i][0] = x - xx;
            coor[i][1] = x + xx;
        }
        if(!flag)
        {
            qsort(coor,n,sizeof(coor[0]),cmp);//����ά���鰴��ͷԪ�صĴ�С�����д�С��������
            res = 1;
            i = 1;
            double right = coor[0][1];
            //ȥ���ض����䲢���������״���Ŀ
            while(i < n)
            {
                if(coor[i][1] < right)
                {
                    right = coor[i][1];
                }
                if(coor[i][0] > right)
                {
                    res++;
                    right = coor[i][1];
                }
                i++;
            }
        }
        printf("Case %d: %d\n",num,res);
        getchar();
    }
    return 0;
}
