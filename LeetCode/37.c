#include <stdio.h>
#include <stdlib.h>

bool isok(char a,int row,int col,char **str) {
  int i,j;
  for(j=0;j<9;j++)//判断当前行是否有重复元素
    if(str[row][j]==a)
      return false;
  for(i=0;i<9;i++)//判断当前列是否有重复元素
    if(str[i][col]==a)
      return false;

  if(row>=0&&row<=2) {
    if(col>=0&&col<=2) {//判断第一个格子是否有重复元素
      for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//判断第二个格子是否有重复元素
      for(i=0;i<=2;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//判断第三个格子是否有重复元素
      for(i=0;i<=2;i++)
        for(j=6;j<=8;j++)
          if(str[i][j]==a)
            return false;
    }
  }

  if(row>=3&&row<=5) {
    if(col>=0&&col<=2) {//判断第四个格子是否有重复元素
      for(i=3;i<=5;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//判断第五个格子是否有重复元素
      for(i=3;i<=5;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//判断第六个格子是否有重复元素
      for(i=3;i<=5;i++)
        for(j=6;j<=8;j++)
          if(str[i][j]==a)
            return false;
    }
  }

  if(row>=6&&row<=8) {
    if(col>=0&&col<=2) {//判断第七个格子是否有重复元素
      for(i=6;i<=8;i++)
        for(j=0;j<=2;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=3&&col<=5) {//判断第八个格子是否有重复元素
      for(i=6;i<=8;i++)
        for(j=3;j<=5;j++)
          if(str[i][j]==a)
            return false;
    }
    if(col>=6&&col<=8) {//判断第九个格子是否有重复元素
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
      if(board[i][j]=='.') {//找到数独中那个没数字的点
        for(k='1';k<='9';k++) {//每个数字进行尝试
          if(isok(k,i,j,board)) {
            board[i][j]=k;//尝试成功就放入进去
            if(solve(board))//下一次的递归调用
              return true;
            else//如果不行的话
              board[i][j]='.';//要将它还原成'.'，因为之前填入了数字
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
