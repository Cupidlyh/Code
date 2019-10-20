#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//map记录皇后放置的位置
int num,map[1000];

void dfs(int k,int n,char ***res){
    if(k == n+1){//当k等于n+1时就说明找到了一种摆放方式
        int x,y = 0;
        for(x = 1; x < k; x++)
            res[num][y++][map[x]-1] = 'Q';
        num++;//num是记录n皇后问题的摆放方式的数量
        return;//回退
    }
    int i,j,flag;
    for(i = 1; i <= n; i++){
        map[k] = i;//尝试当前皇后所放置的位置
        flag = 1;
        for(j = 1; j < k; j++){//当前皇后的位置与之前所有皇后的位置进行判断
            if(map[j] == i || i - k == map[j] - j || i + k == map[j] + j){//满足任意一个就说明皇后摆放的位置不正确
                flag = 0;
                break;
            }
        }
        if(flag == 1)//皇后位置正确
            dfs(k+1,n,res);//递归调用判断下一个皇后的位置
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    memset(map,0,sizeof(map));//初始化
    num = 0;//记录有多少种解法
    int i,j,k;
    char ***res;
    res = (char ***)malloc(sizeof(char **)*1000);//开辟三维数组
    for(i = 0;i < 1000;i++) {
        res[i] = (char **)malloc(sizeof(char*) * (n+1));
        for(j = 0;j < n;j++) {
	        res[i][j] = (char *)malloc(sizeof(char) * (n+1));
		    for(k = 0;k < n;k++){
			    res[i][j][k] = '.';//数组中都初始化为'.'
                res[i][j][k+1] = '\0';//因为是字符串，所以最后要加\0
            }
	    }
    }
    dfs(1,n,res);
    *returnSize = num;//解法的种数
    *returnColumnSizes = (int *)malloc(sizeof(int) * num);
    for(i=0;i<num;i++)
        (*returnColumnSizes)[i] = n;//记录子二维数组的行数
    return res;
}
