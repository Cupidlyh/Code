#include <stdio.h>
#include <stdlib.h>

//i��j�Ƕ�ά������к��е����꣬k�Ǽ�¼Ӧ���ҵ��ʵ��ĸ���ĸ��len�ǵ��ʵĳ��ȣ�row��col��¼���Ƕ�ά��������к�����
bool dfs(char **board,char *word,int i,int j,int k,int len,int row,int col) {
    int next[4][2]={0,1,1,0,0,-1,-1,0};//���ң��£������ƶ�һ��λ�õ�����
    int tx,ty,z;
    if(k==len)//���ҵ���������ʱ
        return true;
    for(z=0;z<4;z++) {//���е��ʵ��������������ϵ�˳��Ѱ��
        tx=i+next[z][0];
        ty=j+next[z][1];
        if(tx<0||ty<0||tx>row-1||ty>col-1)//������ά�������ʱ
            continue;
        if(board[tx][ty]!='*'&&board[tx][ty]==word[k]) {//����ά�����λ��û����ǲ��ҵ��ڵ��ʵ���һ����ĸʱ
            board[tx][ty]='*';//����ά�����λ�ý��б��
            if(dfs(board,word,tx,ty,k+1,len,row,col))//����������һ�ε������������
                return true;
            board[tx][ty]=word[k];//����ʧ��ʱ����ԭ��λ��ԭ������ĸ
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if(strlen(word)==0)//���������ʳ���Ϊ0
        return true;
    int i,j;
    for(i=0;i<boardSize;i++) {//������ά����
        for(j=0;j<* boardColSize;j++) {
            if(board[i][j]==word[0]) {//��ά����Ԫ���뵥������ĸ��ͬ
                board[i][j]='*';//����ǣ������ά�����еĴ���ĸ�ѱ���
                if(dfs(board,word,i,j,1,strlen(word),boardSize,* boardColSize))//�����������
                    return true;
                board[i][j]=word[0];//�����ִ���ĸ��ͷ�޷��ҵ�ʱ��������ԭ
            }
        }
    }
    return false;
}
