#include <stdio.h>
#include <stdlib.h>

//��ѡ������
void SelectSort(int *num,int numSize)
{
    //������num����ѡ������
    int i,j,k;
    for(i = 0; i < numSize; i++)//��num[i..num.size() - 1]��ѡ��ؼ�����С�ļ�¼
    {
        k = i;
        for(j = i + 1; j < numSize; j++)
            if(num[j] < num[k])
                k = j;//kָ����������йؼ�����С�ļ�¼
        if(k != i)
        {
            int temp = num[i];//����num[i]��num[k]
            num[i] = num[k];
            num[k] = temp;
        }
    }
}

int main()
{
    int num[8] = {49,38,65,97,49,13,27,76};
    SelectSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
