#include <stdio.h>
#include <stdlib.h>

//ð������
void BubbleSort(int *num,int numSize)
{
    //������num��ð������
    int len = numSize;
    int flag = 1;//flag�������ĳһ�������Ƿ�������
    while(len >= 2 && flag == 1)
    {
        flag = 0;//flag��Ϊ0�������������û�з��������򲻻�ִ����һ������
        for(int i = 0; i < len - 1; i++)
            if(num[i] > num[i + 1])
            {
                flag = 1;//flag��Ϊ1����ʾ�����������˽���
                //����ǰ����������
                int t = num[i];
                num[i] = num[i + 1];
                num[i + 1] = t;
            }
        len--;
    }
}

int main()
{
    int num[8] = {49,38,65,97,76,13,27,49};
    BubbleSort(num,8);
    for(int i = 0; i < 8; i++)
        printf("%d ",num[i]);
    return 0;
}
