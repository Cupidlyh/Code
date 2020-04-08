#include <stdio.h>
#include <stdlib.h>

//简单选择排序
void SelectSort(int *num,int numSize)
{
    //对数组num做简单选择排序
    int i,j,k;
    for(i = 0; i < numSize; i++)//在num[i..num.size() - 1]中选择关键字最小的记录
    {
        k = i;
        for(j = i + 1; j < numSize; j++)
            if(num[j] < num[k])
                k = j;//k指向此趟排序中关键字最小的记录
        if(k != i)
        {
            int temp = num[i];//交换num[i]和num[k]
            num[i] = num[k];
            num[k] = temp;
        }
    }
}

int main()
{
    int num[8] = {49,38,65,97,49,13,27,76};
    SelectSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
