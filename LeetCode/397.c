#include <stdio.h>
#include <stdlib.h>

int integerReplacement(int n){
        int count=0;
        long long int m=n;//�м��ֹ����int�͵ķ�Χ�������ó�����
        while(m!=1){
            if(m%2==0){//�����ż�����ͳ�2
                m=m/2;
                count++;
            }
            else{
                if((m+1)%4==0&&m!=3){//Ҫ��3�ų���ȥ
                    m=m+1;
                    count++;
                }
                else{
                    m=m-1;
                    count++;
                }
            }
        }
        return count;
}
