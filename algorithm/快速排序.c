#include <stdio.h>
#include <stdlib.h>

//快速排序
int Partition(int *num,int low,int high)
{
    //对子表num[low..high]进行一趟排序，返回枢轴位置
    int pivotkey = num[low];//枢轴记录关键字保存在pivotkey中
    while(low < high)//从表的两端交替地向中间扫描
    {
        while(low < high && num[high] >= pivotkey)
            high--;
        num[low] = num[high];//将比枢轴记录小的移到低端
        while(low < high && num[low] <= pivotkey)
            low++;
        num[high] = num[low];//将比枢轴记录大的移到高端
    }
    num[low] = pivotkey;//枢轴记录关键字记录到位
    return low;//返回枢轴位置
}

void QuickSort(int *num,int low,int high)
{
    //调用前置初值：low = 1；high = num.size() - 1；
    //对数组num中的子序列num[low..high]做快速排序
    if(low < high)//长度大于1
    {
        int pivotloc = Partition(num,low,high);//将num[low..high]一分为二，pivotloc为枢轴位置
        QuickSort(num,low,pivotloc - 1);//对左边数组递归排序
        QuickSort(num,pivotloc + 1,high);//对右边数组递归排序
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    QuickSort(num,0,8 - 1);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
