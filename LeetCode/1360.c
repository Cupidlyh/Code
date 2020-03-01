#include <stdio.h>
#include <stdlib.h>

int year_y(int n) {//判断是否是闰年，1为是，0为不是
    if(n % 4 == 0 && n % 100 != 0)
        return 1;
    if(n % 400 == 0)
        return 1;
    return 0;
}

int daysBetweenDates(char * date1, char * date2){
    int i,y1 = 0,y2 = 0,m1 = 0,m2 = 0,d1 = 0,d2 = 0,temp = 0,y3 = 1000,m3 = 10,d3 = 10,res = 0;
    int run[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};//闰年的月份天数
    int ping[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//平年的月份天数
    for(i = 0; i < strlen(date1); i++) {//将字符串的年份转换成数字存储
        if(date1[i] == '-') {
            temp++;
            continue;
        }
        if(temp == 0) {//算年份
            y1 = y1 + (date1[i] - '0') * y3;
            y2 = y2 + (date2[i] - '0') * y3;
            y3 = y3 / 10;
        }
        if(temp == 1) {//算月份
            m1 = m1 + (date1[i] - '0') * m3;
            m2 = m2 + (date2[i] - '0') * m3;
            m3 = m3 / 10;
        }
        if(temp == 2) {//算日期
            d1 = d1 + (date1[i] - '0') * d3;
            d2 = d2 + (date2[i] - '0') * d3;
            d3 = d3 / 10;
        }
    }
    if(y1 > y2) {//将年份小的存储在前面
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
    if(y1 == y2 && year_y(y1) == 1) {//年份相同且为闰年
        if(m1 == m2)//年份相同月份也相同
            res = abs(d1 - d2);
        if(m1 < m2) {//月份不同
            res = res + run[m1] - d1;//先将此月的天数算满
            m1++;
            while(m1 < m2)//再算m1到m2的整月的天数
                res = res + run[m1];
            res = res + d2;//最后加上m2那月份的天数
        }
        if(m1 > m2) {
            res = res + run[m2] - d2;
            m2++;
            while(m2 < m1)
                res = res + run[m2];
            res = res + d1;
        }
    }
    if(y1 == y2 && year_y(y1) == 0) {//年份相同且为平年
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
    if(y1 != y2) {//年份不同
        if(year_y(y1) == 1) {//起始年为闰年
            res = res + run[m1] - d1;//先将此月的天数算满
            m1++;
            while(m1 <= 12)//再将此年算完（算到12月结束）
                res = res + run[m1++];
            m1 = 1;//月份重新归1
            y1++;//年份加1
        }
        else {
            res = res + ping[m1] - d1;
            m1++;
            while(m1 <= 12)
                res = res + ping[m1++];
            m1 = 1;
            y1++;
        }
        while(y1 < y2) {//再算y1到y2的整年的天数
            if(year_y(y1) == 1)//闰年一年366天
                res = res + 366;
            else//平年一年365
                res = res + 365;
            y1++;
        }
        if(year_y(y2) == 1) {//末尾年是闰年的话
            while(m1 < m2)//再算m1到m2的整月的天数（m1之前归1了）
                res = res + run[m1++];
        }
        else {
           while(m1 < m2)
                res = res + ping[m1++];
        }
        res = res + d2;//最后加上m2那月份的天数
    }
    return res;
}
