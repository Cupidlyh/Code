#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize){
    int i,j,max=0,min,temp,head=0,tail=heightSize-1;
    while(head<tail){
        min=height[head]<height[tail]?height[head]:height[tail];//面积取决于两条边中短的那个
        temp=min*(tail-head);//计算围成的面积
        max=max>temp?max:temp;//取最大值
        if(height[head]<=height[tail])//将指针朝二者中大的那里移动
            head++;
        else
            tail--;
    }
    return max;
}
