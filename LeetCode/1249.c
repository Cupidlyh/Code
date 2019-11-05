#include <stdio.h>
#include <stdlib.h>

char * minRemoveToMakeValid(char * s){//��ջ�����
    char *res = (char *)malloc(sizeof(char) * 100000);//�������

    //sign�Ǳ�����飬temp������¼���ջ�е�ԭ������±�
    int sign[100000] = {0},temp[100000] = {0},head = 0,tail = strlen(s) - 1,i,j = 0;
    char stack[100000] = {'0'};//ջ
    for(i = head; i <= tail; i++) {//��������s����
        if(s[i] == '(') {//��������������ʱ
            stack[j] = '(';//���ջ��
            temp[j] = i;//��¼����s�е��±�
            sign[i] = 1;//���
            j = j + 1;//ջ��ָ���1
        }
        if(s[i] == ')') {//��������������ʱ
            if(j > 0 && stack[j - 1] == '(') {//���ջ��Ԫ����������
                sign[temp[j - 1]] = 0;//��ձ��
                j = j - 1;//ջ��ָ���һ
            }
            else//���ջ��Ԫ�ز���������
                sign[i] = 1;//��Ǵ�λ��s�е�Ԫ��
        }
    }
    j = 0;
    for(i = 0; i < strlen(s); i++)//�����Ľ�����res������
        if(sign[i] == 0)//û����ǵĴ���������
            res[j++] = s[i];
    res[j] = '\0';
    return res;
}
