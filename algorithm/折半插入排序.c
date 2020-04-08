#include <stdio.h>
#include <stdlib.h>

//折半插入排序
void BInsertSort(int *num,int numSize)
{
    //对数组num做折半插入排序
    int temp;
    for(int i = 1; i < numSize; i++)//初始有序段为num[0](只包含一个)
    {
        temp = num[i];//将待插入记录暂存到temp中
        int low = 0,high = i - 1;//重置查找有序段的边界
        while(low <= high)//在[low,high]中折半查找插入的位置
        {
            int mid = (low + high) / 2;//折半
            if(temp < num[mid])//插入点在前一子段
                high = mid - 1;
            else//插入点在后一子段
                low = mid + 1;
        }
        for(int j = i - 1; j >= high + 1; j--)//记录后移
            num[j + 1] = num[j];
        num[high + 1] = temp;//将temp即原num[i]，插入到正确位置
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    BInsertSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
