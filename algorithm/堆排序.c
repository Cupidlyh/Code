#include <stdio.h>
#include <stdlib.h>

//������
void HeapAdjust(int *num,int s,int m)//ɸѡ��������
{
    //����num[s+1..m]�Ѿ��Ƕѣ���num[s..m]����Ϊ��num[s]Ϊ���Ĵ����
    int temp = num[s];
    for(int i = 2 * s; i <= m; i *= 2)//��ֵ�ϴ�ĺ��ӽ������ɸѡ
    {
        if(i < m && num[i] < num[i + 1])
            i++;//iΪ�ϴ�ֵ���±�
        if(temp >= num[i])//tempӦ����λ��s��
            break;
        num[s] = num[i];
        s = i;
    }
    num[s] = temp;//����
}

void CreatHeap(int *num,int numSize)//������
{
    //����������num[0..n]���ɴ����
    int n = numSize - 1;
    for(int i = n / 2; i >= 0; i--)//��������HeapAdjust
        HeapAdjust(num,i,n);
}

void HeapSort(int *num,int numSize)//������
{
    //������num���ж�����
    CreatHeap(num,numSize);//����������num[0..num.size() - 1]���ɴ����
    for(int i = numSize - 1; i > 0; i--)
    {
        int temp = num[0];//���Ѷ���¼�͵�ǰδ������������num[0..i]�����һ����¼����
        num[0] = num[i];
        num[i] = temp;
        HeapAdjust(num,0,i - 1);//��num[0..i-1]���µ���Ϊ�����
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
