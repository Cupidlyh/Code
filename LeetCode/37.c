#include <stdio.h>
#include <stdlib.h>

bool isok(char a,int row,int col,char **str) {
  int i,j;
  for(j=0;j<9;j++)//�жϵ�ǰ���Ƿ����ظ�Ԫ��
    if(str[row][j]==a)
      return false;
  for(i=0;i<9;i++)//�жϵ�ǰ���Ƿ����ظ�Ԫ��
    if(str[i][col]==a)
      return false;

  if(row>=0&&row<=2) {
    if(col>=0&&col<=2) {//�жϵ�һ�������Ƿ����ظ�Ԫ��
      for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//�жϵڶ��������Ƿ����ظ�Ԫ��
      for(i=0;i<=2;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//�жϵ����������Ƿ����ظ�Ԫ��
      for(i=0;i<=2;i++)
        for(j=6;j<=8;j++)
          if(str[i][j]==a)
            return false;
    }
  }

  if(row>=3&&row<=5) {
    if(col>=0&&col<=2) {//�жϵ��ĸ������Ƿ����ظ�Ԫ��
      for(i=3;i<=5;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//�жϵ���������Ƿ����ظ�Ԫ��
      for(i=3;i<=5;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//�жϵ����������Ƿ����ظ�Ԫ��
      for(i=3;i<=5;i++)
        for(j=6;j<=8;j++)
          if(str[i][j]==a)
            return false;
    }
  }

  if(row>=6&&row<=8) {
    if(col>=0&&col<=2) {//�жϵ��߸������Ƿ����ظ�Ԫ��
      for(i=6;i<=8;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//�жϵڰ˸������Ƿ����ظ�Ԫ��
      for(i=6;i<=8;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//�жϵھŸ������Ƿ����ظ�Ԫ��
      for(i=6;i<=8;i++)
        for(j=6;j<=8;j++)
          if(str[i][j]==a)
            return false;
    }
  }
  return true;
}

bool solve(char **board) {
  int i,j;
  char k;
  for(i=0;i<9;i++)
    for(j=0;j<9;j++) {
      if(board[i][j]=='.') {//�ҵ��������Ǹ�û���ֵĵ�
        for(k='1';k<='9';k++) {//ÿ�����ֽ��г���
          if(isok(k,i,j,board)) {
            board[i][j]=k;//���Գɹ��ͷ����ȥ
            if(solve(board))//��һ�εĵݹ����
              return true;
            else//������еĻ�
              board[i][j]='.';//Ҫ������ԭ��'.'����Ϊ֮ǰ����������
          }
        }
        return false;
      }
    }
  return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
  solve(board);
}
