#include <stdio.h>
#include <stdlib.h>

char * intToRoman(int num){
    char *arr=(char *)malloc(1000*sizeof(char));
    memset(arr,0,1000*sizeof(arr[0]));
    int len=log10(num)+1,i,num1,j,num2,k=0,len1=len-1;
    for(i=0;i<len;i++){
        num1=((num/(int)pow(10,len-1-i))%10)*(int)pow(10,len1--);//算出整数的每一位对应的数
        //如果num是425，那么第一次mun1=400,第二次num1=20,第三次num1=5
        if(num1>=1000){
            num2=num1/1000;
            for(j=1;j<=num2;j++)
                arr[k++]='M';
        }
        if(num1==900){
            arr[k++]='C';
            arr[k++]='M';
        }
        if(num1>=500&&num1<900){
            arr[k++]='D';
            num2=(num1-500)/100;
            for(j=1;j<=num2;j++)
                arr[k++]='C';
        }
        if(num1==400){
            arr[k++]='C';
            arr[k++]='D';
        }
        if(num1<400&&num1>=100){
            num2=num1/100;
            for(j=1;j<=num2;j++)
                arr[k++]='C';
        }
        if(num1==90){
            arr[k++]='X';
            arr[k++]='C';
        }
        if(num1>=50&&num1<90){
            arr[k++]='L';
            num2=(num1-50)/10;
            for(j=1;j<=num2;j++)
                arr[k++]='X';
        }
        if(num1==40){
            arr[k++]='X';
            arr[k++]='L';
        }
        if(num1<40&&num1>=10){
            num2=num1/10;
            for(j=1;j<=num2;j++)
                arr[k++]='X';
        }
        if(num1==9){
            arr[k++]='I';
            arr[k++]='X';
        }
        if(num1>=5&&num1<9){
            arr[k++]='V';
            num2=(num1-5)/1;
            for(j=1;j<=num2;j++)
                arr[k++]='I';
        }
        if(num1==4){
            arr[k++]='I';
            arr[k++]='V';
        }
        if(num1<4){
            num2=num1/1;
            for(j=1;j<=num2;j++)
                arr[k++]='I';
        }
    }
    return arr;
}
