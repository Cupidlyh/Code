#include <stdio.h>
#include <stdlib.h>

int sum;

void dfs(int *nums,char *per,int *temp,int *map,int m,int numsSize) {
    if(m==numsSize) {//当所有数字排列完成之后
       sum=sum-1;//排列的个数减1
        if(sum==0) {//当找到第K个排列时
            for(int k=0;k<numsSize;k++)
                per[k]=temp[k]+'0';//将临时存储元素数组中的元素存到结果数组中
        }
        return ;
    }
    int i;
    for(i=0;i<numsSize;i++) {//遍历题目所给的一维数组
        if(map[i]==0){//找到没被标记的数字
        map[i]=1;//将它标记
        temp[m]=nums[i];//将它存进临时存储元素的数组中
        dfs(nums,per,temp,map,m+1,numsSize);
        map[i]=0;//递归调用回退出来时，要将此数字的标记清空
        }
    }
    return ;
}

char * getPermutation(int n, int k){
    int nums[12],i,j=0,temp[n],map[12]={0};//map是标记数组，temp是临时记录元素的数组,nums是存储元素的数组
    sum=k;
    char *per=(char *)malloc((n+1)*sizeof(char));//记录结果的数组
    for(i=1;i<=n;i++)//存储元素进nums数组中
        nums[j++]=i;
    dfs(nums,per,temp,map,0,n);
    per[n]='\0';//结果数组最后要加一个结束符
    return per;

}


