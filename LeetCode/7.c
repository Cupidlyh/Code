#include <stdio.h>
#include <stdlib.h>

int reverse(int x){
    if(x==0||x==-2147483648)//���������ֱ�ӷ��أ�����Ӱ����������
        return 0;
    int i,len,x1=abs(x),len1;//x1Ϊx�ľ���ֵ
    long long int sum=0;//���ܶ����int�ͣ���Ϊ�м��������ܻᳬ��int�ķ�Χ
    len=log10(x1)+1;//���Ƕ����ֳ��ȵļ���
    len1=len-1;
    if(x>0){
        for(i=0;i<len;i++){
            //ǿ������ת��ҲҪת����long long int��������ܳ���int�ķ�Χ
            sum=sum+((x1/(long long int)pow(10,i))%10)*(long long int)pow(10,len1--);
            if(sum>2147483647){//���ܳ���int�����ֵ
                sum=0;
                break;
            }
        }
    }
    if(x<0){
        for(i=0;i<len;i++){
            sum=sum+((x1/(long long int)pow(10,i))%10)*(long long int)pow(10,len1--);
            if(sum>2147483648){//���ܳ���int����Сֵ
                sum=0;
                break;
            }
        }
        sum=sum*-1;//���������Ǹ���ʱ����Ϊ�����ʱ����û�и��ţ���ʱ����
    }
    return sum;
}
