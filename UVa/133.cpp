#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int arr[25];
int n,m,k;

int ClockWise(int b)//顺时针,m
{
    int num = 0,i,flag = 0;
    if(b == 1)
        b = n;
    else
        b -= 1;
    while(true)
    {
        if(i == 0 && flag == 1)
            b = n;
        flag = 1;
        for(i = b; i >= 1; i--)
        {
            if(arr[i] != 0)
                num++;
            if(num == m)
                return i;
        }
    }
    return 0;
}

int UnClockWise(int a)//逆时针,k
{
    int num = 0,i,flag = 0;
    if(a == n)
        a = 1;
    else
        a += 1;
    while(true)
    {
        if(i == n + 1 && flag == 1)
            a = 1;
        flag = 1;
        for(i = a; i <= n; i++)
        {
            if(arr[i] != 0)
                num++;
            if(num == k)
                return i;
        }
    }
    return 0;
}

int main()
{
    int i;
    while(scanf("%d %d %d",&n,&k,&m) != EOF)
    {
        if(n == 0)
            break;
        for(i = 1; i <= n; i++)
            arr[i] = i;
        int sur = n,A = n,B = 1;//A逆时针，B顺时针
        while(sur)
        {
            A = UnClockWise(A);//返回下标
            B = ClockWise(B);
            if(A == B)
            {
                sur--;
                if(sur != 0)
                    printf("%3d,",arr[A]);
                else
                    printf("%3d",arr[A]);
                arr[A] = 0;
            }
            else
            {
                sur -= 2;
                if(sur != 0)
                    printf("%3d%3d,",arr[A],arr[B]);
                else
                    printf("%3d%3d",arr[A],arr[B]);
                arr[A] = 0;
                arr[B] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
