#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int res[100005] = {0};//����洢100005�����������ֵ���С����Ԫ��
int main()
{
    for(int i = 0; i < 100005; i++)
    {
        int temp = i,sum = i;
        while(temp)//�����
        {
            sum += temp % 10;
            temp /= 10;
        }
        if(i < res[sum] || res[sum] == 0)//����Ԫ����
            res[sum] = i;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",res[N]);//������
    }
    return 0;
}
