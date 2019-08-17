#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//比较器
    return *(int *)b-*(int *)a;//从大到小进行排序
}

int maxProfit(int* prices, int pricesSize){
    int arr[50000]={0},i,j,temp=0,max=0;//arr数组存储的是当天出售股票的最大利润
    for(i=0;i<pricesSize;i++){//从头到尾依次遍历
        if(prices[i]<=0)//跳过钱数小于等于0的天数
            continue;
        for(j=i-1;j>=0;j--){
            temp=prices[i]-prices[j];//依次计算此天前购买股票并于今日出售股票的利润
            max=max>temp?max:temp;//取最大值
        }
        arr[i]=max;//存储最大值
    }
    qsort(arr,pricesSize,sizeof(arr[0]),cmp);//排序函数
    return arr[0];
}
