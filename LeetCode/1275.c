#include <stdio.h>
#include <stdlib.h>

int trueee(int i,int j,char map[3][3]) {//判断B是否胜利
    //暴力列出B可能的位置，并进行判断
    if(i == 0 && j == 0) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//第一行
            return 1;
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//第一列
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//主对角线
            return 1;
        return 0;
    }

    if(i == 0 && j == 1) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//第一行
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//第二列
            return 1;
        return 0;
    }

    if(i == 0 && j == 2) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//第一行
            return 1;
        if(map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')//副对角线
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//第三列
            return 1;
        return 0;
    }

    if(i == 1 && j == 0) {
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//第一列
            return 1;
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//第二行
            return 1;
        return 0;
    }

    if(i == 1 && j == 1) {
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//第二行
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//第二列
            return 1;
        if(map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')//副对角线
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//主对角线
            return 1;
        return 0;
    }

    if(i == 1 && j == 2) {
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//第二行
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//第三列
            return 1;
        return 0;
    }

    if(i == 2 && j == 0) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//第三行
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//主对角线
            return 1;
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//第一列
            return 1;
        return 0;
    }

    if(i == 2 && j == 1) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//第三行
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//第二列
            return 1;
        return 0;
    }

    if(i == 2 && j == 2) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//第三行
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//主对角线
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//第三列
            return 1;
        return 0;
    }
    return 0;
}


int truee(int i,int j,char map[3][3]) {//判断A是否胜利
    //暴力列出A可能的位置，并进行判断
    if(i == 0 && j == 0) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//第一行
            return 1;
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//第一列
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//主对角线
            return 1;
        return 0;
    }

    if(i == 0 && j == 1) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//第一行
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//第二列
            return 1;
        return 0;
    }

    if(i == 0 && j == 2) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//第一行
            return 1;
        if(map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')//副对角线
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//第三列
            return 1;
        return 0;
    }

    if(i == 1 && j == 0) {
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//第一列
            return 1;
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//第二行
            return 1;
        return 0;
    }

    if(i == 1 && j == 1) {
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//第二行
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//第二列
            return 1;
        if(map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')//副对角线
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//主对角线
            return 1;
        return 0;
    }

    if(i == 1 && j == 2) {
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//第二行
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//第三列
            return 1;
        return 0;
    }

    if(i == 2 && j == 0) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//第三行
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//主对角线
            return 1;
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//第一列
            return 1;
        return 0;
    }

    if(i == 2 && j == 1) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//第三行
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//第二列
            return 1;
        return 0;
    }

    if(i == 2 && j == 2) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//第三行
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//主对角线
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//第三列
            return 1;
        return 0;
    }
    return 0;
}

void jingziqi(char *res,char map[3][3],int row) {
    int i,j;
    //根据题意假如二人一共走了偶数步数，那么结局就两种，一种B赢，一种游戏未结束
    //如果走了奇数步数，结局要么A赢，要么就是游戏未结束，要么就是平局
    if(row % 2 == 0) {
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++) {
                if(map[i][j] == 'o') {//每找到一个O，就进行判断B是否胜利
                    if(trueee(i,j,map) == 1) {
                        res[0] = 'B';
                        res[1] = '\0';
                        return ;
                    }
                }
            }
        strcpy(res,"Pending");
            return;
    }
    else {
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++) {
                if(map[i][j] == 'x') {//每找到一个X，就进行判断A是否胜利
                    if(truee(i,j,map) == 1) {
                        res[0] = 'A';
                        res[1] = '\0';
                        return ;
                    }
                }
            }
        //井字棋最多二人一共走九步
        if(row < 9) {
            strcpy(res,"Pending");
            return;
        }
        else {
            strcpy(res,"Draw");
            return;
        }
    }
    return ;
}

char * tictactoe(int** moves, int movesSize, int* movesColSize){
    char * res = (char *)malloc(sizeof(char) * 8);
    if(movesSize < 5) {//小于五步没人会赢
        strcpy(res,"Pending");
        return res;
    }
    char map[3][3] = {'0'};
    int i;
    for(i = 0; i < movesSize; i++){//先存入下棋的地图
        if(i % 2 == 0) {
            map[moves[i][0]][moves[i][1]] = 'x';
        }
        else {
            map[moves[i][0]][moves[i][1]] = 'o';
        }
    }
    jingziqi(res,map,movesSize);
    return res;
}
