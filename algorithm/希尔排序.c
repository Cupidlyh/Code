#include <stdio.h>
#include <stdlib.h>

//ϣ������
void ShellInsert(int *num,int numSize,int dk)
{
    //������num��һ��������dk��ϣ����������
    int temp;
    int i,j;
    for(i = dk; i < numSize; i++)
    {
        if(num[i] < num[i - dk])//С�ڣ���Ҫ��num[i]���뵽���������Ӷ���
        {
            temp = num[i];//���������¼�ݴ浽temp��
            for(j = i - dk; j >= 0 && num[j] > temp; j -= dk)
                num[j + dk] = num[j];//��¼������ƣ�ֱ���ҵ�����λ��
            num[j + dk] = temp;//��temp��ԭnum[i]�����뵽��ȷλ��
        }
    }
}

int main()
{
    int num[10] = {49,38,65,97,76,13,27,49,55,4};
    int dt[3] = {5,3,1};//��������(��������ȡֵ����Ӧ��ʹ������û�г�1����Ĺ����ӣ��������һ������ֵ����Ϊ1)
    for(int k = 0; k < 3; k++)
        ShellInsert(num,10,dt[k]);//һ������Ϊdt[k]��ϣ����������
    for(int i = 0; i < 10; i++)
        printf("%d ",num[i]);
    return 0;
}
