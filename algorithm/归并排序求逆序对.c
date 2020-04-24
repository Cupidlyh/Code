#include <stdio.h>
#include <stdlib.h>

int ans;//记录数组中逆序对的个数

//归并排序
void MergeSort(int *R,int *T,int low,int high)
{
    //R[low..high]归并排序后放入T[low..high]
    if(low == high)
        T[low] = R[low];
    else
    {
        int mid = (low + high) / 2;//将当前数组一分为二，求出分裂点mid
        MergeSort(R,T,low,mid);//对子数组R[low..mid]递归归并排序，结果放入T[low..mid]
        MergeSort(R,T,mid + 1,high);//对子数组R[mid+1..high]递归归并排序，结果放入T[mid+1..high]

        //将有序数组R[low..mid]和R[mid+1..high]归并为有序数组T[low..high]
        int i = low,j = mid + 1,k = low;
        while(i <= mid && j <= high)//将R中的记录由小到大地并入T中
        {
            if(R[i] <= R[j])
                T[k++] = R[i++];
            else
            {
                T[k++] = R[j++];
                ans += (mid - i + 1);
            }
        }
        while(i <= mid)//将剩余的R[i..mid]复制到T中
            T[k++] = R[i++];
        while(j <= high)//将剩余的R[j..high]复制到T中
            T[k++] = R[j++];
        //将有序数组T[low,k-1]赋值给R[low,k-1]
        for(j = low; j < k; j++)
            R[j] = T[j];
    }
}

int main()
{
    ans = 0;//求逆序对的时候要注意所求数组大小要大于0
    int num[7] = {49,38,65,97,76,13,27};
    int *T = (int *)malloc(sizeof(int) * 7);
    MergeSort(num,T,0,7 - 1);
    for(int i = 0; i < 7; i++)
        printf("%d ",num[i]);
    printf("\n%d\n",ans);
    return 0;
}
