#include <stdio.h>
#include <stdlib.h>

int evalRPN(char ** tokens, int tokensSize){
    long long int arr[10000] = {0};//������ֵ�ջ
    int top = 0;//ջ��ָ��
    for(int i=0;i<tokensSize;i++) {//������Ŀ�����Ķ�ά����
        if(strlen(tokens[i]) == 1) {//��ǰ�г���Ϊһʱ
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9')//�����һλ���־ʹ��ջ��
                arr[top++] = tokens[i][0] - '0';
            else {//����ֻ��һλ����һλ���־��������
                switch(tokens[i][0])//�ж����ĸ������
                {
                    case '+':
                        arr[top-2] = arr[top-2] + arr[top-1];
                        top = top - 1;
                        break;
                    case '-':
                        arr[top-2] = arr[top-2] - arr[top-1];
                        top = top - 1;
                        break;
                    case '*':
                        arr[top-2] = arr[top-2] * arr[top-1];
                        top = top - 1;
                        break;
                    case '/':
                        arr[top-2] = arr[top-2] / arr[top-1];
                        top = top - 1;
                        break;
                }
            }
        }
        else {//��ǰ�г��ȴ���һʱ
            int sum = 0,num = 0;
            if(tokens[i][0] != '-') {//���Ǹ��������
                for(int j=strlen(tokens[i])-1;j>=0;j--) {
                    sum = sum + (int)pow(10,num++) * (tokens[i][j] - '0');//���ַ������ּ�������͵�����
                }
                arr[top++] = sum;
            }
            else {//�Ǹ��������
                for(int j=strlen(tokens[i])-1;j>0;j--) {
                    sum = sum + (int)pow(10,num++) * (tokens[i][j] - '0');
                }
                arr[top++] = -sum;
            }
        }
    }
    return arr[0];
}
