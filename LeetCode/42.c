#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int heightSize){
    if(heightSize==0||heightSize==1)
        return 0;
    int left=0,right=heightSize-1,left_max=height[left],right_max=height[right],ans=0;
     while(left<right){//循环条件
        if (height[left]<height[right]) {//哪边短就从哪边开始算起
            left_max=left_max>height[left]?left_max:height[left];//取高的柱子的长度
            ans=ans+left_max-height[left];//计算接的雨水量
            left++;
        }
        else {
            right_max=right_max>height[right]?right_max:height[right];
            ans=ans+right_max-height[right];
            right--;
        }
    }
    return ans;
}
