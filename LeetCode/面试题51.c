int ans;
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
            else {
                T[k++] = R[j++];
                ans += (mid - i + 1);//新添加的一行代码（计算逆序对的个数）
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

int reversePairs(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    ans = 0;
    int *T = (int *)malloc(sizeof(int) * numsSize);
    MergeSort(nums,T,0,numsSize - 1);
    return ans;
}
