#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize){
    int i,j,max=0,min,temp,head=0,tail=heightSize-1;
    while(head<tail){
        min=height[head]<height[tail]?height[head]:height[tail];//���ȡ�����������ж̵��Ǹ�
        temp=min*(tail-head);//����Χ�ɵ����
        max=max>temp?max:temp;//ȡ���ֵ
        if(height[head]<=height[tail])//��ָ�볯�����д�������ƶ�
            head++;
        else
            tail--;
    }
    return max;
}
