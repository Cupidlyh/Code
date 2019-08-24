#include <stdio.h>
#include <stdlib.h>

//i和j是二维数组的行和列的坐标，k是记录应该找单词的哪个字母，len是单词的长度，row和col记录的是二维数组的总行和列数
bool dfs(char **board,char *word,int i,int j,int k,int len,int row,int col) {
    int next[4][2]={0,1,1,0,0,-1,-1,0};//往右，下，左，上移动一个位置的坐标
    int tx,ty,z;
    if(k==len)//当找到所给单词时
        return true;
    for(z=0;z<4;z++) {//进行单词的搜索，右下左上的顺序寻找
        tx=i+next[z][0];
        ty=j+next[z][1];
        if(tx<0||ty<0||tx>row-1||ty>col-1)//超出二维数组界限时
            continue;
        if(board[tx][ty]!='*'&&board[tx][ty]==word[k]) {//当二维数组此位置没被标记并且等于单词的下一个字母时
            board[tx][ty]='*';//将二维数组此位置进行标记
            if(dfs(board,word,tx,ty,k+1,len,row,col))//继续进行下一次的深度优先搜索
                return true;
            board[tx][ty]=word[k];//搜索失败时，还原此位置原来的字母
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if(strlen(word)==0)//当所给单词长度为0
        return true;
    int i,j;
    for(i=0;i<boardSize;i++) {//遍历二维数组
        for(j=0;j<* boardColSize;j++) {
            if(board[i][j]==word[0]) {//二维数组元素与单词首字母相同
                board[i][j]='*';//做标记，代表二维数组中的此字母已被用
                if(dfs(board,word,i,j,1,strlen(word),boardSize,* boardColSize))//深度优先搜索
                    return true;
                board[i][j]=word[0];//当发现此字母开头无法找到时，将它复原
            }
        }
    }
    return false;
}
