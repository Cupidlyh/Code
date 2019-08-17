#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int heightSize){
    if(heightSize==0||heightSize==1)
        return 0;
    int left=0,right=heightSize-1,left_max=height[left],right_max=height[right],ans=0;
     while(left<right){//ѭ������
        if (height[left]<height[right]) {//�ı߶̾ʹ��ı߿�ʼ����
            left_max=left_max>height[left]?left_max:height[left];//ȡ�ߵ����ӵĳ���
            ans=ans+left_max-height[left];//����ӵ���ˮ��
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
