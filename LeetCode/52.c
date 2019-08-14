#include <stdio.h>
#include <stdlib.h>

static int num,map[10000];//ȫ�ֱ���

void dfs(int k,int n){
    if(k==n+1){//��k����n+1ʱ��˵���ҵ���һ�ְڷŷ�ʽ
        num++;//num�Ǽ�¼n�ʺ�����İڷŷ�ʽ������
        return;//����
    }
    int i,j,flag;
    for(i=1;i<=n;i++){
        map[k]=i;//���Ե�ǰ�ʺ������õ�λ��
        flag=1;
        for(j=1;j<k;j++){//��ǰ�ʺ��λ����֮ǰ���лʺ��λ�ý����ж�
            if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j){//��������һ����˵���ʺ�ڷŵ�λ�ò���ȷ
                flag=0;
                break;
            }
        }
        if(flag==1)//�ʺ�λ����ȷ
            dfs(k+1,n);//�ݹ�����ж���һ���ʺ��λ��
    }
}

int totalNQueens(int n){
    num=0;//��ʼ��
    memset(map,0,sizeof(map));//��ʼ��
    dfs(1,n);
    return num;
}
