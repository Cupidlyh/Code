#include <stdio.h>
#include <stdlib.h>

int arr[200000],arr1[200000];

int calculate(char * s){
    int slen=strlen(s),i,num=0,sum,num1=0,bit;//bit是记录位数
    memset(arr,0,sizeof(arr));//初始化数组
    memset(arr1,0,sizeof(arr1));//初始化数组
    for(i=0;i<slen;i++) {//将符号用数字记录
        sum = 0;
        bit = 0;
        if(s[i] == ' ')
            continue;
        if(s[i] == '+')
            arr[num++] = -1;
        if(s[i] == '-')
            arr[num++] = -2;
        if(s[i] == '*')
            arr[num++] = -3;
        if(s[i] == '/')
            arr[num++] = -4;
        if(s[i] >= '0' && s[i] <= '9') {//将多位数转成整型存起来
            int temp = i;
            while(i <= slen - 1 && s[i] >= '0' && s[i] <= '9')
                i = i + 1;
            for(int j=i-1;j>=temp;j--)
                sum = sum + pow(10,bit++) * (s[j] - '0');
            arr[num++] = sum;
            i = i -1;
        }
    }

    for(i=0;i<num;i++) {//先将arr数组中乘法和除法计算出来存储，其余原样存储
        if(arr[i] != -3 && arr[i] != -4)
            arr1[num1++] = arr[i];
        if(arr[i] == -3) {
            int cf = arr[i-1];
            do{
                if(arr[i] == -3){
                    cf = cf * arr[i+1];
                    i = i + 2;
                }
                if(arr[i] == -4){
                    cf = cf / arr[i+1];
                    i = i + 2;
                }
            }while(arr[i] == -3 || arr[i] == -4);
            arr1[num1-1] = cf;
            i = i - 1;
            continue;
        }
        if(arr[i] == -4) {
            int cf = arr[i-1];
            do{
                if(arr[i] == -3){
                    cf = cf * arr[i+1];
                    i = i + 2;
                }
                if(arr[i] == -4){
                    cf = cf / arr[i+1];
                    i = i + 2;
                }
            }while(arr[i] == -3 || arr[i] == -4);
            arr1[num1-1] = cf;
            i = i - 1;
            continue;
        }
    }

    sum = 0;
    sum = sum + arr1[0];
    for(i=1;i<num1-1;i=i+2) {//计算加减运算
        if(arr1[i] == -1)
            sum = sum + arr1[i+1];
        if(arr1[i] == -2)
            sum = sum - arr1[i+1];
    }
    return sum;
}
