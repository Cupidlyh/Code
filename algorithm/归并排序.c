#include <stdio.h>
#include <stdlib.h>

int numSize;

//归并排序
void Merge(int *R,int *T,int low,int mid,int high)
{
    //将有序数组R[low..mid]和R[mid+1..high]归并为有序数组T[low..high]
    int i = low,j = mid + 1,k = low;
    while(i <= mid && j <= high)//将R中的记录由小到大地并入T中
    {
        if(R[i] <= R[j])
            T[k++] = R[i++];
        else
            T[k++] = R[j++];
    }
    while(i <= mid)//将剩余的R[i..mid]复制到T中
        T[k++] = R[i++];
    while(j <= high)//将剩余的R[j..high]复制到T中
        T[k++] = R[j++];
}

void MergeSort(int *R,int *T,int low,int high)
{
    //R[low..high]归并排序后放入T[low..high]
    if(low == high)
        T[low] = R[low];
    else
    {
        int *S = (int *)malloc(sizeof(int) * numSize);
        int mid = (low + high) / 2;//将当前数组一分为二，求出分裂点mid
        MergeSort(R,S,low,mid);//对子数组R[low..mid]递归归并排序，结果放入S[low..mid]
        MergeSort(R,S,mid + 1,high);//对子数组R[mid+1..high]递归归并排序，结果放入S[mid+1..high]
        Merge(S,T,low,mid,high);//将S[low..mid]和S[mid+1..high]归并到T[low..high]
    }
}

int main()
{
    int num[7] = {49,38,65,97,76,13,27};
    numSize = 7;
    MergeSort(num,num,0,7 - 1);
    for(int i = 0; i < 7; i++)
        printf("%d ",num[i]);
    return 0;
}
