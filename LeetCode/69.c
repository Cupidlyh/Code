#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    int n=46340,i;//��Ϊint�͵����ֵ��ƽ��ȡ������46340
                  //����n��ֵΪ46340
    for(i=1;i<=46340;i++){//i���ܵ���46341
                          //���������i*i�Ľ���ᳬ��int�͵ķ�Χ
        if(i*i==x){
            n=i;
            break;
        }
        if(i*i>x){
            n=i-1;//������ʱҪ��ȥһ��
            break;
        }
    }
    return n;
}
