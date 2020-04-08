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
    int book[10];//记录数字i在arr中出现的次数
    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        printf("Game %d:\n",++exa);
        int i;
        for(i = 0; i < N; i++)//存入当前正确的数字
            scanf("%d",&arr[i]);
        while(true)
        {
            int A = 0,B = 0;
            memset(book,0,sizeof(book));
            for(i = 0; i < N; i++)//存入猜的数字
            {
                scanf("%d",&arr1[i]);
                if(arr1[i] == arr[i])//相等A就加1
                    A++;
                else//不等此数字出现次数加1
                    book[arr[i]]++;
            }
            if(arr1[0] == 0)//正常猜不会猜0，首位为0就是结束了当前的猜数字
                break;
            for(i = 0; i < N; i++)//遍历猜数字的数组arr1
            {
                //当前位数字与正确的数字不相等，且当前位数字在正确数字中存在，B加1（就是消除的意思，想不明白自己画一下就懂了）
                if(arr1[i] != arr[i] && book[arr1[i]]-- > 0)
                    B++;
            }
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
