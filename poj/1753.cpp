#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

char s[10];
int mapp[20];//存储16个棋子的状态（1到16）
int flag;//标记是否找出符合条件的轮数

int pan()//判断是否全黑或全白
{
    int x = mapp[1];
    for(int i = 2; i <= 16; i++)
        if(mapp[i] != x)
            return 0;
    return 1;
}

void fan(int x)//翻转棋子颜色
{
    mapp[x] = !mapp[x];
    if(x + 4 <= 16)
        mapp[x + 4] = !mapp[x + 4];
    if(x - 4 >= 1)
        mapp[x - 4] = !mapp[x - 4];
    if(x % 4 == 0)
        mapp[x - 1] = !mapp[x - 1];
    else if(x % 4 == 1)
        mapp[x + 1] = !mapp[x + 1];
    else
    {
        mapp[x - 1] = !mapp[x - 1];
        mapp[x + 1] = !mapp[x + 1];
    }
}

//x是下标，num是剩余翻转棋子数
void dfs(int x,int num)//利用dfs进行枚举
{
    if(num == 0)//可翻转棋子数为0
    {
        if(pan())//如果符合条件
            flag = 1;//标记
        return ;
    }
    int i;
    for(i = x + 1; i <= 16; i++)
    {
        if(i + num > 17)//深搜的剪枝（剩下的棋子数不够你翻转的，用前面的就会有重复的情况）
            return ;
        fan(i);//翻转
        dfs(i,num - 1);
        fan(i);//状态还原
        if(flag)//找到满足的就没必要继续深搜了
            return ;
    }
    return ;
}

int main()
{
    int i,j;
    flag = 0;
    int bit = 1;
    for (i = 0; i < 4; i++)//读入数据并存储
    {
        scanf("%s",s);
        for(j = 0; j < 4; j++)
        {
            if(s[j] == 'b')
                mapp[bit++] = 0;
            else
                mapp[bit++] = 1;
        }
    }
    if(pan())//步骤为0先判断下
        printf("0\n");
    else
    {
        for(i = 1; i <= 16; i++)//1到16为可翻转棋子数（利用深搜枚举出翻转的所有组合）
        {
            dfs(0,i);//深度优先搜索
            if(flag)//如果符合条件，不用继续了，直接跳出
                break;
        }
        if(!flag)//flag为0说明没有符合条件的翻转棋子数
            printf("Impossible\n");
        else
            printf("%d\n",i);
    }


    return 0;
}
