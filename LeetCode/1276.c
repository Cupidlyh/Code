#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if(tomatoSlices == 0 && cheeseSlices == 0)  //原材料都为0的情况
    {
        res[0] = 0;
        res[1] = 0;
        return res;
    }
    //此题就是数学题，我们设巨无霸做x个，小黄堡做y个
    //4x + 2y = tomatoSlices    x + y = cheeseSlices
    //剩下的就是解方程组了
    int temp = tomatoSlices - (2 * cheeseSlices);
    double x,y;
    x = temp / 2.0;//解出巨无霸的数量
    if(x < 0 || (x - (int)x) > 0)//如果小于零或不是整数
    {
        *returnSize = 0;//无解
        return res;
    }
    y = cheeseSlices - x;//解出小黄堡的数量
    if(y < 0 || (y - (int)y) > 0)//如果小于零或不是整数
    {
        *returnSize = 0;//无解
        return res;
    }
    res[0] = x;
    res[1] = y;
    return res;
}
