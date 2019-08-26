#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int row;

void dfs(int *nums,int *map,int numsSize,int colu,int *col,int **arr) {
    int i;
    if(colu==numsSize) {//当所有数字排列完成之后
        if(row==0) {//如果是第0行
            col[row]=numsSize;
            row=row+1;////下一种情况存在下一行
            for(i=0;i<numsSize;i++)//将此种情况存进下一行中，因为之后会用到
                arr[row][i]=arr[row-1][i];
        }
        if(row>0) {//如果是第0行之后的行
            int flag=0,j,k;
            k=row;
            for(i=row-1;i>=0;i--) {//通过比较来判断是否有重复序列
                for(j=0;j<numsSize;j++) {
                    if(arr[k][j]!=arr[i][j])
                        break;
                    if(arr[k][j]==arr[i][j]) {
                        if(j==numsSize-1) {//如果出现有和之前相同的排列
                            flag=1;//flag标记为1
                            break;
                        }
                    }
                }
                if(flag==1)//flag为1即为找到重复
                    break;//跳出循环
            }
            if(flag==0) {//当没找到重复序列时
                col[row]=numsSize;
                row=row+1;//行加1，以便下次的存储
                for(i=0;i<numsSize;i++)//将此种情况存进下一行中，因为之后会用到
                    arr[row][i]=arr[row-1][i];
            }
        }
        return ;
    }
    for(i=0;i<numsSize;i++) {//遍历题目所给的一维数组
        if(map[i]==0) {//找到没被标记的数字
            arr[row][colu]=nums[i];//存进二维数组中
            map[i]=1;//将此数字标记
            dfs(nums,map,numsSize,colu+1,col,arr);//递归调用
            map[i]=0;//递归调用回退出来时，要将此数字的标记清空
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,colu=0;//colu表示即将存进二维数组的哪一列
    row=0;//全局变量，表示即将存进二维数组的哪一行
    int *col=(int *)malloc(5000*sizeof(int));
    int **arr =(int **)malloc(sizeof(int*)*5000);//开辟二维数组
    for(i=0; i<5000; i++)
        arr[i]=(int *)malloc(sizeof(int)*100);
    int *map=(int *)malloc(numsSize*sizeof(int));//开辟一个一维的标记数组
    memset(map,0,numsSize*sizeof(int));//数组初始化
    dfs(nums,map,numsSize,colu,col,arr);
    *returnSize=row;
    *returnColumnSizes=col;
    return arr;
}
