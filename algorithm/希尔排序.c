#include <stdio.h>
#include <stdlib.h>

//希尔排序
void ShellInsert(int *num,int numSize,int dk)
{
    //对数组num做一趟增量是dk的希尔插入排序
    int temp;
    int i,j;
    for(i = dk; i < numSize; i++)
    {
        if(num[i] < num[i - dk])//小于，需要将num[i]插入到有序增量子段中
        {
            temp = num[i];//将待插入记录暂存到temp中
            for(j = i - dk; j >= 0 && num[j] > temp; j -= dk)
                num[j + dk] = num[j];//记录逐个后移，直到找到插入位置
            num[j + dk] = temp;//将temp即原num[i]，插入到正确位置
        }
    }
}

int main()
{
    int num[10] = {49,38,65,97,76,13,27,49,55,4};
    int dt[3] = {5,3,1};//增量序列(可以任意取值，但应该使序列中没有除1以外的公因子，并且最后一个增量值必须为1)
    for(int k = 0; k < 3; k++)
        ShellInsert(num,10,dt[k]);//一趟增量为dt[k]的希尔插入排序
    for(int i = 0; i < 10; i++)
        printf("%d ",num[i]);
    return 0;
}
