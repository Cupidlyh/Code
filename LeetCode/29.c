#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor){
    if(dividend==divisor)//�����ͱ��������ʱ
        return 1;

    if(dividend==INT_MIN) {//��������Ϊ������Сֵʱ
        if(divisor==1)//����Ϊ1ʱ
            return dividend;
        if(divisor==-1)//����Ϊ-1ʱ
            return INT_MAX;
    }
    //������Ϊ������Сֵʱ���߱������ľ���ֵС�ڳ����ľ���ֵ
    if(divisor==INT_MIN||labs(dividend)<labs(divisor))
        return 0;
    if(divisor==1){//������Ϊ1ʱ
        return dividend;
    }

    int sum=0,i=0;//sum��¼������ӵĺͣ�i��¼������ӵ�����
    int div=dividend,iso=divisor;

    if(div>0&&iso>0){//�������ͳ���������0ʱ
        while(iso<=429496729&&5*iso<=div-sum) {//��������������εļ�
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso<=div-sum) {//��һ��һ�εļ�
            sum=sum+iso;
            i=i+1;
        }

    }

    if(div<0&&iso<0) {//�������ͳ�����С��0ʱ
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }

    }

    if(div>0&&iso<0) {//����������0������С��0ʱ
        div=-div;//��Ϊ��������Сֵ�ľ���ֵ�����������ֵ�����Ի��ɸ���
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }
        i=-i;//����Ǹ���
    }

    if(div<0&&iso>0) {//������С��0����������0ʱ
        iso=-iso;
        while(iso>=-429496729&&5*iso>=div-sum) {
            sum=sum+5*iso;
            i=i+5;
        }
        while(iso>=div-sum) {
            sum=sum+iso;
            i=i+1;
        }
        i=-i;
    }

    return i;
}
