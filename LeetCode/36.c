#include <stdio.h>
#include <stdlib.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i,j,k;
    for(i=0;i<boardSize;i++){//�ж�ÿһ���Ƿ���������
        int arr[10]={0};//������¼���ֳ��ֵĴ���
        for(j=0;j<* boardColSize;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        for(k=0;k<10;k++)
            if(arr[k]>=2)//ĳһ�����ֳ������������ϾͲ���һ����ȷ������
                return false;
    }
    for(i=0;i<* boardColSize;i++){//�ж�ÿһ���Ƿ���������
        int arr[10]={0};
        for(j=0;j<boardSize;j++){
            if(board[j][i]>='0'&&board[j][i]<='9')
                arr[board[j][i]-'0']++;
        }
        for(k=0;k<10;k++)
            if(arr[k]>=2)
                return false;
    }
    int arr[10]={0};
    for(i=0;i<boardSize;i++){//�ж���ߵ�����С�������е������Ƿ���������
        for(j=0;j<3;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        if((i+1)%3==0){//ÿ���������������У����if�����ж��Ƿ��Ѿ�������һ��������
            for(k=0;k<10;k++)
                if(arr[k]>=2)
                   return false;
            memset(arr,0,sizeof(arr));//������Ϊ0�ĺ���
        }
    }
    for(i=0;i<boardSize;i++){//�ж��м������С�������е������Ƿ���������
        for(j=3;j<6;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        if((i+1)%3==0){
            for(k=0;k<10;k++)
                if(arr[k]>=2)
                   return false;
            memset(arr,0,sizeof(arr));
        }
    }
    for(i=0;i<boardSize;i++){//�ж��ұߵ�����С�������е������Ƿ���������
        for(j=6;j<9;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        if((i+1)%3==0){
            for(k=0;k<10;k++)
                if(arr[k]>=2)
                   return false;
            memset(arr,0,sizeof(arr));
        }
    }
    return true;
}
