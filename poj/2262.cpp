#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int pr[1000000];//-1����ǰ�±��������������0����������

void is_prime()//�ж���Щ����������
{
    int i,j;
    pr[0] = 0;
    pr[1] = 0;
    for(i = 2; i * i <= 1000000; i++)
    {
        if(pr[i])
        {
            j = i + i;
            while(j < 1000000)
            {
                pr[j] = 0;
                j += i;
            }
        }
    }
}

int main()
{
    int n;
    memset(pr,-1,sizeof(pr));
    is_prime();
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        int a = 0,b = 0,i;
        for(i = n - 2; i >= n / 2; i--)//�Ӻ���ǰ��������֤�ҵ��ĵ�һ�����ǲ�ֵ����
        {
            if(pr[i] && pr[n - i])
            {
                b = i;
                a = n - i;
                break;
            }
        }
        if(!a && !b)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n",n,a,b);
    }
    return 0;
}
