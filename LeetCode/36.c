#include <stdio.h>
#include <stdlib.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i,j,k;
    for(i=0;i<boardSize;i++){//判断每一行是否满足条件
        int arr[10]={0};//用来记录数字出现的次数
        for(j=0;j<* boardColSize;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        for(k=0;k<10;k++)
            if(arr[k]>=2)//某一个数字出现了两次以上就不是一个正确的数独
                return false;
    }
    for(i=0;i<* boardColSize;i++){//判断每一列是否满足条件
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
    for(i=0;i<boardSize;i++){//判断左边的三个小正方形中的数字是否满足条件
        for(j=0;j<3;j++){
            if(board[i][j]>='0'&&board[i][j]<='9')
                arr[board[i][j]-'0']++;
        }
        if((i+1)%3==0){//每个正方行三行三列，这个if用来判断是否已经遍历了一个正方形
            for(k=0;k<10;k++)
                if(arr[k]>=2)
                   return false;
            memset(arr,0,sizeof(arr));//数组置为0的函数
        }
    }
    for(i=0;i<boardSize;i++){//判断中间的三个小正方形中的数字是否满足条件
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
    for(i=0;i<boardSize;i++){//判断右边的三个小正方形中的数字是否满足条件
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
