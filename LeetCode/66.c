#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *arr=(int *)malloc(1000*sizeof(int));
    memset(arr,0,sizeof(arr));//��ʼ������
    int i,j=1;//��ĿҪ���1������j��ʼֵΪ1
    if(digits[0]==0){//��������������Ϊ0ʱ�����жϣ�����ֵȻ�󷵻�
        arr[0]=1;
        *returnSize=digitsSize;//returnSize�Ĵ�Сȡ����������������Ĵ�С
        return arr;
    }
    else{//�����鲻������0ʱ
        for(i=digitsSize-1;i>=0;i--){//���ֵ������������һλ��ʼ����
            if(digits[i]+j>=10){//������ڵ���10����Ҫ��λ
                arr[i+1]=(digits[i]+j)%10;//֮���Դ���i+1����ΪԤ���ռ䣬��ֹ����99��������ʱ
                                          //����ĳ�����Ҫ��һ
                j=(digits[i]+j)/10;//jΪ�´�������Ҫ����λ
            }
            else{
                arr[i+1]=digits[i]+j;
                j=0;//���С��10���Ͳ����ٽ�λ��
            }
        }
    }
    if(j!=0)//���forѭ��������jֵ��Ϊ�㣬˵������Ҫ��λ
            //��ʱԤ���Ŀռ�����洢���ֵ
        arr[0]=j;
    if(arr[0]==0){//���arr[0]Ϊ0��˵��û����
    *returnSize=digitsSize;//��С���ش������Ĵ�С�Ϳ���
     return arr+1;//Ҫע������ķ�����arr+1����Ϊarr[0]=0���ǲ�ϣ������
    }
    else
        *returnSize=digitsSize+1;//���arr[0]�����ˣ���ô���صĳ��Ⱦ�Ҫ��ԭ���ĳ��ȶ�һ��
    return arr;
}
