#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//�Ƚ���
    return *(int *)b-*(int *)a;//�Ӵ�С��������
}

int maxProfit(int* prices, int pricesSize){
    int arr[50000]={0},i,j,temp=0,max=0;//arr����洢���ǵ�����۹�Ʊ���������
    for(i=0;i<pricesSize;i++){//��ͷ��β���α���
        if(prices[i]<=0)//����Ǯ��С�ڵ���0������
            continue;
        for(j=i-1;j>=0;j--){
            temp=prices[i]-prices[j];//���μ������ǰ�����Ʊ���ڽ��ճ��۹�Ʊ������
            max=max>temp?max:temp;//ȡ���ֵ
        }
        arr[i]=max;//�洢���ֵ
    }
    qsort(arr,pricesSize,sizeof(arr[0]),cmp);//������
    return arr[0];
}
