#include <stdio.h>
#include <stdlib.h>


int maxProfit(int* prices, int pricesSize){
    int i,j,temp=0,max=0;
    for(i=0;i<pricesSize;i++){//��ͷ��β���α���
        if(prices[i]<=0)//����Ǯ��С�ڵ���0������
            continue;
        for(j=i-1;j>=0;j--){
            temp=prices[i]-prices[j];//���μ������ǰ�����Ʊ���ڽ��ճ��۹�Ʊ������
            max=max>temp?max:temp;//ȡ���ֵ
        }
    }
    return max;
}
