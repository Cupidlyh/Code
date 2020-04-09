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
            stack<int>s;//栈
            s.push(1);//先进栈一个
            int maxx = 1;//记录栈中的最大值
            for(i = 1; i <= N; i++)
            {
                if(arr[i] == s.top())
                {
                    int temp = s.top();
                    s.pop();
                    if(s.empty())//如果栈空那就进栈一个
                    {
                        s.push(temp + 1);
                        maxx = temp + 1;//更新
                    }
                }
                else
                {
                    if(s.top() > arr[i])
                    {
                        flag = 0;
                        break;
                    }
                    for(j = maxx + 1; j <= arr[i]; j++)//进栈要从栈中最大值加1开始到当前不等的这个值
                    {
                        s.push(j);
                    }
                    maxx = maxx > arr[i] ? maxx : arr[i];//更新
                    i--;//因为当前比较不等所以下次还需要比较当前的，所以i减1
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
