#include <stdio.h>
#include <stdlib.h>

//直接插入排序
void InsertSort(int *num,int numSize)
{
    int temp;
    int i,j;
    for(i = 1; i < numSize; i++)//初始有序段为num[0](只包含一个)
    {
        if(num[i] < num[i - 1])//小于，需要将num[i]插入有序段中
        {
            temp = num[i];//将待插入记录暂存到temp中
            num[i] = num[i - 1];//num[i-1]后移
            for(j = i - 2; j >= 0 && temp < num[j]; j--)//从后向前寻找插入位置
            {
                num[j + 1] = num[j];//记录逐个后移，直到找到插入位置
            }
            num[j + 1] = temp;//将temp即原num[i]，插入到正确位置
        }
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    InsertSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
