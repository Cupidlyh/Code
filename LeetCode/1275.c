#include <stdio.h>
#include <stdlib.h>

int trueee(int i,int j,char map[3][3]) {//�ж�B�Ƿ�ʤ��
    //�����г�B���ܵ�λ�ã��������ж�
    if(i == 0 && j == 0) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//��һ��
            return 1;
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//��һ��
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//���Խ���
            return 1;
        return 0;
    }

    if(i == 0 && j == 1) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//��һ��
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 0 && j == 2) {
        if(map[0][0] == 'o' && map[0][1] == 'o' && map[0][2] == 'o')//��һ��
            return 1;
        if(map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')//���Խ���
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//������
            return 1;
        return 0;
    }

    if(i == 1 && j == 0) {
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//��һ��
            return 1;
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 1 && j == 1) {
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//�ڶ���
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//�ڶ���
            return 1;
        if(map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')//���Խ���
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//���Խ���
            return 1;
        return 0;
    }

    if(i == 1 && j == 2) {
        if(map[1][0] == 'o' && map[1][1] == 'o' && map[1][2] == 'o')//�ڶ���
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//������
            return 1;
        return 0;
    }

    if(i == 2 && j == 0) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//������
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//���Խ���
            return 1;
        if(map[0][0] == 'o' && map[1][0] == 'o' && map[2][0] == 'o')//��һ��
            return 1;
        return 0;
    }

    if(i == 2 && j == 1) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//������
            return 1;
        if(map[0][1] == 'o' && map[1][1] == 'o' && map[2][1] == 'o')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 2 && j == 2) {
        if(map[2][0] == 'o' && map[2][1] == 'o' && map[2][2] == 'o')//������
            return 1;
        if(map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')//���Խ���
            return 1;
        if(map[0][2] == 'o' && map[1][2] == 'o' && map[2][2] == 'o')//������
            return 1;
        return 0;
    }
    return 0;
}


int truee(int i,int j,char map[3][3]) {//�ж�A�Ƿ�ʤ��
    //�����г�A���ܵ�λ�ã��������ж�
    if(i == 0 && j == 0) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//��һ��
            return 1;
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//��һ��
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//���Խ���
            return 1;
        return 0;
    }

    if(i == 0 && j == 1) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//��һ��
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 0 && j == 2) {
        if(map[0][0] == 'x' && map[0][1] == 'x' && map[0][2] == 'x')//��һ��
            return 1;
        if(map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')//���Խ���
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//������
            return 1;
        return 0;
    }

    if(i == 1 && j == 0) {
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//��һ��
            return 1;
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 1 && j == 1) {
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//�ڶ���
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//�ڶ���
            return 1;
        if(map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')//���Խ���
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//���Խ���
            return 1;
        return 0;
    }

    if(i == 1 && j == 2) {
        if(map[1][0] == 'x' && map[1][1] == 'x' && map[1][2] == 'x')//�ڶ���
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//������
            return 1;
        return 0;
    }

    if(i == 2 && j == 0) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//������
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//���Խ���
            return 1;
        if(map[0][0] == 'x' && map[1][0] == 'x' && map[2][0] == 'x')//��һ��
            return 1;
        return 0;
    }

    if(i == 2 && j == 1) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//������
            return 1;
        if(map[0][1] == 'x' && map[1][1] == 'x' && map[2][1] == 'x')//�ڶ���
            return 1;
        return 0;
    }

    if(i == 2 && j == 2) {
        if(map[2][0] == 'x' && map[2][1] == 'x' && map[2][2] == 'x')//������
            return 1;
        if(map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')//���Խ���
            return 1;
        if(map[0][2] == 'x' && map[1][2] == 'x' && map[2][2] == 'x')//������
            return 1;
        return 0;
    }
    return 0;
}

void jingziqi(char *res,char map[3][3],int row) {
    int i,j;
    //��������������һ������ż����������ô��־����֣�һ��BӮ��һ����Ϸδ����
    //��������������������ҪôAӮ��Ҫô������Ϸδ������Ҫô����ƽ��
    if(row % 2 == 0) {
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++) {
                if(map[i][j] == 'o') {//ÿ�ҵ�һ��O���ͽ����ж�B�Ƿ�ʤ��
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
                if(map[i][j] == 'x') {//ÿ�ҵ�һ��X���ͽ����ж�A�Ƿ�ʤ��
                    if(truee(i,j,map) == 1) {
                        res[0] = 'A';
                        res[1] = '\0';
                        return ;
                    }
                }
            }
        //������������һ���߾Ų�
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
    if(movesSize < 5) {//С���岽û�˻�Ӯ
        strcpy(res,"Pending");
        return res;
    }
    char map[3][3] = {'0'};
    int i;
    for(i = 0; i < movesSize; i++){//�ȴ�������ĵ�ͼ
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
