int ans;
//�鲢����
void MergeSort(int *R,int *T,int low,int high)
{
    //R[low..high]�鲢��������T[low..high]
    if(low == high)
        T[low] = R[low];
    else
    {
        int mid = (low + high) / 2;//����ǰ����һ��Ϊ����������ѵ�mid
        MergeSort(R,T,low,mid);//��������R[low..mid]�ݹ�鲢���򣬽������T[low..mid]
        MergeSort(R,T,mid + 1,high);//��������R[mid+1..high]�ݹ�鲢���򣬽������T[mid+1..high]

        //����������R[low..mid]��R[mid+1..high]�鲢Ϊ��������T[low..high]
        int i = low,j = mid + 1,k = low;
        while(i <= mid && j <= high)//��R�еļ�¼��С����ز���T��
        {
            if(R[i] <= R[j])
                T[k++] = R[i++];
            else {
                T[k++] = R[j++];
                ans += (mid - i + 1);//����ӵ�һ�д��루��������Եĸ�����
            }
        }
        while(i <= mid)//��ʣ���R[i..mid]���Ƶ�T��
            T[k++] = R[i++];
        while(j <= high)//��ʣ���R[j..high]���Ƶ�T��
            T[k++] = R[j++];
        //����������T[low,k-1]��ֵ��R[low,k-1]
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
