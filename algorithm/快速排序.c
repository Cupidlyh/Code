#include <stdio.h>
#include <stdlib.h>

//��������
int Partition(int *num,int low,int high)
{
    //���ӱ�num[low..high]����һ�����򣬷�������λ��
    int pivotkey = num[low];//�����¼�ؼ��ֱ�����pivotkey��
    while(low < high)//�ӱ�����˽�������м�ɨ��
    {
        while(low < high && num[high] >= pivotkey)
            high--;
        num[low] = num[high];//���������¼С���Ƶ��Ͷ�
        while(low < high && num[low] <= pivotkey)
            low++;
        num[high] = num[low];//���������¼����Ƶ��߶�
    }
    num[low] = pivotkey;//�����¼�ؼ��ּ�¼��λ
    return low;//��������λ��
}

void QuickSort(int *num,int low,int high)
{
    //����ǰ�ó�ֵ��low = 1��high = num.size() - 1��
    //������num�е�������num[low..high]����������
    if(low < high)//���ȴ���1
    {
        int pivotloc = Partition(num,low,high);//��num[low..high]һ��Ϊ����pivotlocΪ����λ��
        QuickSort(num,low,pivotloc - 1);//���������ݹ�����
        QuickSort(num,pivotloc + 1,high);//���ұ�����ݹ�����
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
