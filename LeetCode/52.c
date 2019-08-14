#include <stdio.h>
#include <stdlib.h>

static int num,map[10000];//全局变量

void dfs(int k,int n){
    if(k==n+1){//当k等于n+1时就说明找到了一种摆放方式
        num++;//num是记录n皇后问题的摆放方式的数量
        return;//回退
    }
    int i,j,flag;
    for(i=1;i<=n;i++){
        map[k]=i;//尝试当前皇后所放置的位置
        flag=1;
        for(j=1;j<k;j++){//当前皇后的位置与之前所有皇后的位置进行判断
            if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j){//满足任意一个就说明皇后摆放的位置不正确
                flag=0;
                break;
            }
        }
        if(flag==1)//皇后位置正确
            dfs(k+1,n);//递归调用判断下一个皇后的位置
    }
}

int totalNQueens(int n){
    num=0;//初始化
    memset(map,0,sizeof(map));//初始化
    dfs(1,n);
    return num;
}
