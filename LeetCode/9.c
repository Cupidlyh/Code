#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x){
    if(x<0)//����һ�����ǻ�����
        return false;
    if(x>=0&&x<=9)//λ��Ϊ1������һ���ǻ�����
        return true;
    if(x>=10){
        int len=log10(x)+1,len1=(len+1)/2,i,j=len-1;//lenΪ�������ֵ�λ����len1Ϊ�ȽϵĴ���
        for(i=1;i<=len1;i++){
            if((x/(int)pow(10,j))%10!=(x%(int)pow(10,i))/(int)pow(10,i-1)){//ͨ����ѧ����ȡ��ÿһλ������
                                                                           //�����бȽ�
                return false;
            }
            j--;
        }
    }
    return true;
}


