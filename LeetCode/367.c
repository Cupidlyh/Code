#include <stdio.h>
#include <stdlib.h>

bool isPerfectSquare(int num){
    int i;
    for(i=1;i<=46340;i++){//��Ϊint�����ֵ�����ź�Ľ��������������46340
                          //����i���ȡֵ46340
        if(i*i==num)//���ʱ����true��˵������ȫƽ����
            return true;
        if(i*i>num)//������ʱ��˵������������ȫƽ����
            break;
    }
    return false;
}
