#include <stdio.h>
#include <stdlib.h>

//冒泡排序
void BubbleSort(int *num,int numSize)
{
    //对数组num做冒泡排序
    int len = numSize;
    int flag = 1;//flag用来标记某一趟排序是否发生交换
    while(len >= 2 && flag == 1)
    {
        flag = 0;//flag置为0，如果本趟排序没有发生交换则不会执行下一趟排序
        for(int i = 0; i < len - 1; i++)
            if(num[i] > num[i + 1])
            {
                flag = 1;//flag置为1，表示本趟排序发生了交换
                //交换前后两个数字
                int t = num[i];
                num[i] = num[i + 1];
                num[i + 1] = t;
            }
        len--;
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    BubbleSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
