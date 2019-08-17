#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    int i,j,temp=0,max=0;
    for(i=0;i<pricesSize;i++){//从头到尾依次遍历
        if(prices[i]<=0)//跳过钱数小于等于0的天数
            continue;
        for(j=i-1;j>=0;j--){
            temp=prices[i]-prices[j];//依次计算此天前购买股票并于今日出售股票的利润
            max=max>temp?max:temp;//取最大值
        }
    }
    return max;
}
