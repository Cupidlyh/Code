#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int arr[1005],arr1[1005],N,exa = 0;
    int book[10];//��¼����i��arr�г��ֵĴ���
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        printf("Game %d:\n",++exa);
        int i;
        for(i = 0; i < N; i++)//���뵱ǰ��ȷ������
            scanf("%d",&arr[i]);
        while(true)
        {
            int A = 0,B = 0;
            memset(book,0,sizeof(book));
            for(i = 0; i < N; i++)//����µ�����
            {
                scanf("%d",&arr1[i]);
                if(arr1[i] == arr[i])//���A�ͼ�1
                    A++;
                else//���ȴ����ֳ��ִ�����1
                    book[arr[i]]++;
            }
            if(arr1[0] == 0)//�����²����0����λΪ0���ǽ����˵�ǰ�Ĳ�����
                break;
            for(i = 0; i < N; i++)//���������ֵ�����arr1
            {
                //��ǰλ��������ȷ�����ֲ���ȣ��ҵ�ǰλ��������ȷ�����д��ڣ�B��1��������������˼���벻�����Լ���һ�¾Ͷ��ˣ�
                if(arr1[i] != arr[i] && book[arr1[i]]-- > 0)
                    B++;
            }
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
