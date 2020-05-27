#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

char s[10];
int mapp[20];//�洢16�����ӵ�״̬��1��16��
int flag;//����Ƿ��ҳ���������������

int pan()//�ж��Ƿ�ȫ�ڻ�ȫ��
{
    int x = mapp[1];
    for(int i = 2; i <= 16; i++)
        if(mapp[i] != x)
            return 0;
    return 1;
}

void fan(int x)//��ת������ɫ
{
    mapp[x] = !mapp[x];
    if(x + 4 <= 16)
        mapp[x + 4] = !mapp[x + 4];
    if(x - 4 >= 1)
        mapp[x - 4] = !mapp[x - 4];
    if(x % 4 == 0)
        mapp[x - 1] = !mapp[x - 1];
    else if(x % 4 == 1)
        mapp[x + 1] = !mapp[x + 1];
    else
    {
        mapp[x - 1] = !mapp[x - 1];
        mapp[x + 1] = !mapp[x + 1];
    }
}

//x���±꣬num��ʣ�෭ת������
void dfs(int x,int num)//����dfs����ö��
{
    if(num == 0)//�ɷ�ת������Ϊ0
    {
        if(pan())//�����������
            flag = 1;//���
        return ;
    }
    int i;
    for(i = x + 1; i <= 16; i++)
    {
        if(i + num > 17)//���ѵļ�֦��ʣ�µ������������㷭ת�ģ���ǰ��ľͻ����ظ��������
            return ;
        fan(i);//��ת
        dfs(i,num - 1);
        fan(i);//״̬��ԭ
        if(flag)//�ҵ�����ľ�û��Ҫ����������
            return ;
    }
    return ;
}

int main()
{
    int i,j;
    flag = 0;
    int bit = 1;
    for (i = 0; i < 4; i++)//�������ݲ��洢
    {
        scanf("%s",s);
        for(j = 0; j < 4; j++)
        {
            if(s[j] == 'b')
                mapp[bit++] = 0;
            else
                mapp[bit++] = 1;
        }
    }
    if(pan())//����Ϊ0���ж���
        printf("0\n");
    else
    {
        for(i = 1; i <= 16; i++)//1��16Ϊ�ɷ�ת����������������ö�ٳ���ת��������ϣ�
        {
            dfs(0,i);//�����������
            if(flag)//����������������ü����ˣ�ֱ������
                break;
        }
        if(!flag)//flagΪ0˵��û�з��������ķ�ת������
            printf("Impossible\n");
        else
            printf("%d\n",i);
    }


    return 0;
}
