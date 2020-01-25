#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tx[1005];//�洢�����ϱ߽��������
int ty[1005];
int bx[1005];//�洢�����±߽��������
int by[1005];
int num[1005];//��¼ÿ�������������
double k[1005];//�������ֱ�ߵ�б��
double b[1005];//ֱ�߹�ʽ�е�b(y = k * x + b)
int num1[1005];//ͳ����һ����������ĸ�����

int main()
{
    int n,m,x1,x2,y1,y2;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d %d %d %d %d",&m,&x1,&y1,&x2,&y2);
        memset(num,0,sizeof(num));
        memset(num1,0,sizeof(num1));
        int i,j,U,L,x,y,flag;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&U,&L);
            tx[i] = U;
            ty[i] = y1;
            bx[i] = L;
            by[i] = y2;
        }
        for(i = 0; i < n; i++)//�����尴�յײ��ĺ������С������������
        {
            for(j = i + 1; j < n; j++)
            {
                if(bx[i] > bx[j])
                {
                    int k;
                    k = bx[i];
                    bx[i] = bx[j];
                    bx[j] = k;
                    k = tx[i];
                    tx[i] = tx[j];
                    tx[j] = k;
                }
            }
        }
        for(i = 0; i < n; i++)//��������ֱ�߱��ʽ
        {
            if(tx[i] == bx[i])//��������ֱ���������б�ʵģ���ֱ��x�ᣩ
            {
                k[i] = 0;
            }
            else//�������ֱ���
            {
                k[i] = ((double)ty[i] - (double)by[i]) / (tx[i] - bx[i]);
                b[i] = ty[i] - k[i] * tx[i];
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
        {
            if(num[j] > 0)//ͳ�ƺ�����ͬ������ĸ�������
                num1[num[j]]++;
        }
        printf("Box\n");
        for(j = 1; j <= m; j++)
        {
            if(num1[j] > 0)
                printf("%d: %d\n",j,num1[j]);
        }
    }
    return 0;
}
