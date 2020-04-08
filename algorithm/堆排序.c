#include <stdio.h>
#include <stdlib.h>

//堆排序
void HeapAdjust(int *num,int s,int m)//筛选法调整堆
{
    //假设num[s+1..m]已经是堆，将num[s..m]调整为以num[s]为根的大根堆
    int temp = num[s];
    for(int i = 2 * s; i <= m; i *= 2)//沿值较大的孩子结点向下筛选
    {
        if(i < m && num[i] < num[i + 1])
            i++;//i为较大值的下标
        if(temp >= num[i])//temp应插在位置s上
            break;
        num[s] = num[i];
        s = i;
    }
    num[s] = temp;//插入
}

void CreatHeap(int *num,int numSize)//建初堆
{
    //把无序数组num[0..n]建成大根堆
    int n = numSize - 1;
    for(int i = n / 2; i >= 0; i--)//反复调用HeapAdjust
        HeapAdjust(num,i,n);
}

void HeapSort(int *num,int numSize)//堆排序
{
    //对数组num进行堆排序
    CreatHeap(num,numSize);//把无序数组num[0..num.size() - 1]建成大根堆
    for(int i = numSize - 1; i > 0; i--)
    {
        int temp = num[0];//将堆顶记录和当前未经排序子数组num[0..i]中最后一个记录互换
        num[0] = num[i];
        num[i] = temp;
        HeapAdjust(num,0,i - 1);//将num[0..i-1]重新调整为大根堆
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    HeapSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
