#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *arr=(int *)malloc(1000*sizeof(int));
    memset(arr,0,sizeof(arr));//初始化数组
    int i,j=1;//题目要求加1，所以j初始值为1
    if(digits[0]==0){//如果所传入的数组为0时单独判断，并赋值然后返回
        arr[0]=1;
        *returnSize=digitsSize;//returnSize的大小取决于你所返回数组的大小
        return arr;
    }
    else{//当数组不是数字0时
        for(i=digitsSize-1;i>=0;i--){//数字的相加运算从最后一位开始运算
            if(digits[i]+j>=10){//如果大于等于10，就要进位
                arr[i+1]=(digits[i]+j)%10;//之所以存在i+1是因为预留空间，防止出现99这种数字时
                                          //数组的长度需要加一
                j=(digits[i]+j)/10;//j为下次运算需要进几位
            }
            else{
                arr[i+1]=digits[i]+j;
                j=0;//如果小于10，就不用再进位了
            }
        }
    }
    if(j!=0)//如果for循环结束，j值不为零，说明还需要进位
            //此时预留的空间就来存储这个值
        arr[0]=j;
    if(arr[0]==0){//如果arr[0]为0，说明没用上
    *returnSize=digitsSize;//大小返回传进来的大小就可以
     return arr+1;//要注意这里的返回是arr+1，因为arr[0]=0我们不希望返回
    }
    else
        *returnSize=digitsSize+1;//如果arr[0]用上了，那么返回的长度就要比原来的长度多一个
    return arr;
}
