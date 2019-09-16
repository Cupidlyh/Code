#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

iint dlen,row;//dlen�Ǽ�¼�����������ַ�����ĳ��ȣ�row��¼������󷵻��������
//digits����Ŀ���������飬arr�������Լ����ٵļ�¼��������飬n�Ǽ�¼digits���������λ�ã�col��¼arr����洢��������
void dfs(char *digits,char **arr,int n,int col) {
    if(n==dlen) {//��digits�����������ʱ
        arr[row][col]='\0';
        row=row+1;//������һ����ʼ��һ�еĴ洢
        int k;
        for(k=0;k<=dlen;k++)//�����ȱ�������һ�еĽ������Ϊ���ݽ�������һ�εĽ��
            arr[row][k]=arr[row-1][k];
        return ;
    }

    if(digits[n]=='2') {//����Ϊ2ʱ��������Ӧ����ĸ���δ��arr�����в����еݹ����
        arr[row][col]='a';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='b';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='c';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='3') {
        arr[row][col]='d';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='e';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='f';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='4') {
        arr[row][col]='g';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='h';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='i';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='5') {
        arr[row][col]='j';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='k';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='l';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='6') {
        arr[row][col]='m';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='n';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='o';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='7') {
        arr[row][col]='p';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='q';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='r';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='s';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='8') {
        arr[row][col]='t';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='u';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='v';
        dfs(digits,arr,n+1,col+1);
    }

    if(digits[n]=='9') {
        arr[row][col]='w';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='x';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='y';
        dfs(digits,arr,n+1,col+1);
        arr[row][col]='z';
        dfs(digits,arr,n+1,col+1);
    }
    return ;
}

char ** letterCombinations(char * digits, int* returnSize){
    int i;
    dlen=strlen(digits);
    row=0;
    char **arr =(char **)malloc(sizeof(char*)*20000);//���ٶ�ά����
    for(i=0; i<20000; i++)
        arr[i]=(char *)malloc(sizeof(char)*(dlen+1));
    if(dlen==0) {//���������鳤��Ϊ0ʱ
        *returnSize=0;
        return arr;
    }
    dfs(digits,arr,0,0);//�ݹ����
    *returnSize=row;
    return arr;
}
