#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tx[5005];//�洢�����ϱ߽��������
int ty[5005];
int bx[5005];//�洢�����±߽��������
int by[5005];
int num[5005];//��¼ÿ�������������
double k[5005];//�������ֱ�ߵ�б��
double b[5005];//ֱ�߹�ʽ�е�b(y = k * x + b)

int main()
{
    int n,m,x1,x2,y1,y2;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d %d %d %d %d",&m,&x1,&y1,&x2,&y2);
        memset(num,0,sizeof(num));
        int i,j,U,L,x,y,flag;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&U,&L);
            tx[i] = U;
            ty[i] = y1;
            bx[i] = L;
            by[i] = y2;
            if(U == L)//��������ֱ���������б�ʵģ���ֱ��x�ᣩ
            {
                k[i] = 0;
            }
            else//�������ֱ���
            {
                k[i] = ((double)y1 - (double)y2) / (U - L);
                b[i] = y1 - k[i] * U;
            }
        }
        double temp;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d",&x,&y);
            flag = 0;
            for(j = 0; j < n; j++)
            {
                temp = k[j] * x + b[j];//�����ǰ���x��ֱ���ϵ�y����
                if(k[j] == 0 && x < tx[j])//б��Ϊ0ʱ����������С�ڵ�ǰ����ĺ�����
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
                if(k[j] > 0 && y > temp)//б��������������ڵ�ǰ�����ǵ�ǰ���y�����Ҫ������ֱ���������y���꣨����temp��
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
                if(k[j] < 0 && y < temp)//б���Ǹ���������ڵ�ǰ�����ǵ�ǰ���y�����ҪС����ֱ���������y���꣨����temp��
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)//�������Ǹ�������һ��������ǰ��ĸ����Ǿ������һ������
                num[j]++;
        }
        for(j = 0; j <= n; j++)
            printf("%d: %d\n",j,num[j]);
        printf("\n");
    }
    return 0;
}
