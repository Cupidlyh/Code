#include <stdio.h>
#include <stdlib.h>

int year_y(int n) {//�ж��Ƿ������꣬1Ϊ�ǣ�0Ϊ����
    if(n % 4 == 0 && n % 100 != 0)
        return 1;
    if(n % 400 == 0)
        return 1;
    return 0;
}

int daysBetweenDates(char * date1, char * date2){
    int i,y1 = 0,y2 = 0,m1 = 0,m2 = 0,d1 = 0,d2 = 0,temp = 0,y3 = 1000,m3 = 10,d3 = 10,res = 0;
    int run[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};//������·�����
    int ping[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//ƽ����·�����
    for(i = 0; i < strlen(date1); i++) {//���ַ��������ת�������ִ洢
        if(date1[i] == '-') {
            temp++;
            continue;
        }
        if(temp == 0) {//�����
            y1 = y1 + (date1[i] - '0') * y3;
            y2 = y2 + (date2[i] - '0') * y3;
            y3 = y3 / 10;
        }
        if(temp == 1) {//���·�
            m1 = m1 + (date1[i] - '0') * m3;
            m2 = m2 + (date2[i] - '0') * m3;
            m3 = m3 / 10;
        }
        if(temp == 2) {//������
            d1 = d1 + (date1[i] - '0') * d3;
            d2 = d2 + (date2[i] - '0') * d3;
            d3 = d3 / 10;
        }
    }
    if(y1 > y2) {//�����С�Ĵ洢��ǰ��
        temp = y1;
        y1 = y2;
        y2 = temp;
        temp = m1;
        m1 = m2;
        m2 = temp;
        temp = d1;
        d1 = d2;
        d2 = temp;
    }
    if(y1 == y2 && year_y(y1) == 1) {//�����ͬ��Ϊ����
        if(m1 == m2)//�����ͬ�·�Ҳ��ͬ
            res = abs(d1 - d2);
        if(m1 < m2) {//�·ݲ�ͬ
            res = res + run[m1] - d1;//�Ƚ����µ���������
            m1++;
            while(m1 < m2)//����m1��m2�����µ�����
                res = res + run[m1];
            res = res + d2;//������m2���·ݵ�����
        }
        if(m1 > m2) {
            res = res + run[m2] - d2;
            m2++;
            while(m2 < m1)
                res = res + run[m2];
            res = res + d1;
        }
    }
    if(y1 == y2 && year_y(y1) == 0) {//�����ͬ��Ϊƽ��
        if(m1 == m2)
            res = abs(d1 - d2);
        if(m1 < m2) {
            res = res + ping[m1] - d1;
            m1++;
            while(m1 < m2)
                res = res + ping[m1];
            res = res + d2;
        }
        if(m1 > m2) {
            res = res + ping[m2] - d2;
            m2++;
            while(m2 < m1)
                res = res + ping[m2];
            res = res + d1;
        }
    }
    if(y1 != y2) {//��ݲ�ͬ
        if(year_y(y1) == 1) {//��ʼ��Ϊ����
            res = res + run[m1] - d1;//�Ƚ����µ���������
            m1++;
            while(m1 <= 12)//�ٽ��������꣨�㵽12�½�����
                res = res + run[m1++];
            m1 = 1;//�·����¹�1
            y1++;//��ݼ�1
        }
        else {
            res = res + ping[m1] - d1;
            m1++;
            while(m1 <= 12)
                res = res + ping[m1++];
            m1 = 1;
            y1++;
        }
        while(y1 < y2) {//����y1��y2�����������
            if(year_y(y1) == 1)//����һ��366��
                res = res + 366;
            else//ƽ��һ��365
                res = res + 365;
            y1++;
        }
        if(year_y(y2) == 1) {//ĩβ��������Ļ�
            while(m1 < m2)//����m1��m2�����µ�������m1֮ǰ��1�ˣ�
                res = res + run[m1++];
        }
        else {
           while(m1 < m2)
                res = res + ping[m1++];
        }
        res = res + d2;//������m2���·ݵ�����
    }
    return res;
}
