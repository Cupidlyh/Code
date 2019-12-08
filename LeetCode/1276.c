#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if(tomatoSlices == 0 && cheeseSlices == 0)  //ԭ���϶�Ϊ0�����
    {
        res[0] = 0;
        res[1] = 0;
        return res;
    }
    //���������ѧ�⣬��������ް���x����С�Ʊ���y��
    //4x + 2y = tomatoSlices    x + y = cheeseSlices
    //ʣ�µľ��ǽⷽ������
    int temp = tomatoSlices - (2 * cheeseSlices);
    double x,y;
    x = temp / 2.0;//������ްԵ�����
    if(x < 0 || (x - (int)x) > 0)//���С�����������
    {
        *returnSize = 0;//�޽�
        return res;
    }
    y = cheeseSlices - x;//���С�Ʊ�������
    if(y < 0 || (y - (int)y) > 0)//���С�����������
    {
        *returnSize = 0;//�޽�
        return res;
    }
    res[0] = x;
    res[1] = y;
    return res;
}
