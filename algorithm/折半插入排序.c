#include <stdio.h>
#include <stdlib.h>

//�۰��������
void BInsertSort(int *num,int numSize)
{
    //������num���۰��������
    int temp;
    for(int i = 1; i < numSize; i++)//��ʼ�����Ϊnum[0](ֻ����һ��)
    {
        temp = num[i];//���������¼�ݴ浽temp��
        int low = 0,high = i - 1;//���ò�������εı߽�
        while(low <= high)//��[low,high]���۰���Ҳ����λ��
        {
            int mid = (low + high) / 2;//�۰�
            if(temp < num[mid])//�������ǰһ�Ӷ�
                high = mid - 1;
            else//������ں�һ�Ӷ�
                low = mid + 1;
        }
        for(int j = i - 1; j >= high + 1; j--)//��¼����
            num[j + 1] = num[j];
        num[high + 1] = temp;//��temp��ԭnum[i]�����뵽��ȷλ��
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
