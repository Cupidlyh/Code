#include <stdio.h>
#include <stdlib.h>

int ans;//��¼����������Եĸ���

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
            else
            {
                T[k++] = R[j++];
                ans += (mid - i + 1);
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

int main()
{
    ans = 0;
    int num[7] = {49,38,65,97,76,13,27};
    int *T = (int *)malloc(sizeof(int) * 7);
    MergeSort(num,T,0,7 - 1);
    for(int i = 0; i < 7; i++)
        printf("%d ",num[i]);
    printf("\n%d\n",ans);
    return 0;
}
