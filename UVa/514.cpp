#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    int N,i,j,arr[1005];
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        while(true)
        {
            int flag = 0;
            for(i = 1; i <= N; i++)
            {
                scanf("%d",&arr[i]);
                if(arr[1] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
            flag = 1;
            stack<int>s;//ջ
            s.push(1);//�Ƚ�ջһ��
            int maxx = 1;//��¼ջ�е����ֵ
            for(i = 1; i <= N; i++)
            {
                if(arr[i] == s.top())
                {
                    int temp = s.top();
                    s.pop();
                    if(s.empty())//���ջ���Ǿͽ�ջһ��
                    {
                        s.push(temp + 1);
                        maxx = temp + 1;//����
                    }
                }
                else
                {
                    if(s.top() > arr[i])
                    {
                        flag = 0;
                        break;
                    }
                    for(j = maxx + 1; j <= arr[i]; j++)//��ջҪ��ջ�����ֵ��1��ʼ����ǰ���ȵ����ֵ
                    {
                        s.push(j);
                    }
                    maxx = maxx > arr[i] ? maxx : arr[i];//����
                    i--;//��Ϊ��ǰ�Ƚϲ��������´λ���Ҫ�Ƚϵ�ǰ�ģ�����i��1
                }
            }
            if(flag == 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        printf("\n");
    }
    return 0;
}
