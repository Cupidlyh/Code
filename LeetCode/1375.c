#include <stdio.h>
#include <stdlib.h>

int numTimesAllBlue(int* light, int lightSize){
    int max = 0,num = 0,i;
    for(i = 0; i < lightSize; i++) {
        max = max > light[i] ? max : light[i];
        if(max == i + 1)//如果当前最大亮起来的灯等于遍历过的灯的数量，那么说明前面的灯都亮了
            num++;//结果数加1
    }
    return num;
}
