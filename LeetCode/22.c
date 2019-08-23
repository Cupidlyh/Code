#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int col,row;
//left�����������˼�����right�����������˼���
void gen(int left,int right,int n,char **str) {
  if(left==n&&right==n) {//�������Ŷ�����ʱ
    int i;
    str[row][col]='\0';//�ַ���������־
    row++;//��������һ�д���һ�����
    for(i=0;i<2*n;i++)
      str[row][i]=str[row-1][i];//����һ������浽��һ���У���Ϊ�ݹ��������һ�����������һ�ֵĻ����Ͻ��е�
    return ;
  }
  if(left<n) {//������û����ʱ
    str[row][col++]='(';//�����Ŵ���
    gen(left+1,right,n,str);//�����ż�1���ݹ�
    col=col-1;//���ݹ��˳���ʱ��������һ�γ��ԣ�������1
  }
  if(left>right&&right<n) {//������û���겢�������Ÿ�������
    str[row][col++]=')';//�����Ŵ���
    gen(left,right+1,n,str);//�����ż�1���ݹ�
    col=col-1;//���ݹ��˳���ʱ��������һ�γ��ԣ�������1
  }
}

char ** generateParenthesis(int n, int* returnSize){
  int i;
  char **str =(char **)malloc(sizeof(char*)*5000);//����һ����ά���飬��5000��
    for(i=0; i<5000; i++)
        str[i]=(char *)malloc(sizeof(char)*5000);//ÿһ��5000��
  col=0;//��¼��
  row=0;//��¼��
  gen(0,0,n,str);
  *returnSize=row;//��������
  return str;
}
