#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
next[i]��ʾ�����ַ���str1���Ӵ� str1[0..i] ��ļ���ǰ׺Ҳ�Ǻ�׺���ַ���(����ǰ��׺��ԭ�ַ������ص�)
������ַ��������� str1[0..i] �������統�ַ���Ϊ str1 = abacaba ʱ��
aba ������ļ���ǰ׺Ҳ�Ǻ�׺���ַ�����next[6] ��ֵΪ 2��ע���ַ������±��Ǵ� 0 ��ʼ�ģ�
str1 ��ǰ׺ str1[0..2] �ͺ�׺ str1[4..6] ��Ϊ aba��
*/

void pre_next(int *next,char *str,int len)
{
    int k = -1,i;
    for(i = 1; i < len; i++)
    {
        while(k > -1 && str[k + 1] != str[i])
            k = next[k];
        if(str[k + 1] == str[i])
            k++;
        next[i] = k;
    }
}

int main()
{
    char str[1000] = {0},str1[1000] = {0};
    int next[1000],k = -1;
    memset(next,-1,sizeof(next));
    printf("���������������Ȳ�����1000\n");
    scanf("%s",str);
    printf("�������Ӵ������Ȳ�����1000\n");
    scanf("%s",str1);
    int len = strlen(str),len1 = strlen(str1),i,ans = 0;
    pre_next(next,str1,len1);
    for(i = 0; i < len; i++)
    {
        while(k > -1 && str1[k + 1] != str[i])
            k = next[k];
        if(str1[k + 1] == str[i])
            k++;
        if(k == len1-1)
        {
            ans=i-len1+1;//ֻҪ�ҵ��Ӵ���һ�γ��ֵ�λ��
            break;//��������ѭ��
        }

        /*int count=0;
        if(k==len1-1)//�����if�жϻ������־���ͳ�������г����˼����Ӵ�����׼������һ���Ӵ��е�Ԫ�أ�
        {
            count++;
            k=-1;
        }*/


        /*int count=0;
        if(k==len1-1)//�����if�жϻ������־���ͳ�������г����˼����Ӵ������Խ�����һ���Ӵ��е�Ԫ�أ�
        {
            count++;
            i=i-len1+1;
            k=-1;
        }*/
    }
    printf("�Ӵ��״γ����������е���ţ�%d\n",ans);
    return 0;
}
