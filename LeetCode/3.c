#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int max=0,len=strlen(s),i,num=0,j;
    int arr[150]={0};//������飬����ַ��Ƿ���ֹ�
    for(j=0;j<len;j++){//ÿ���ַ���Ϊ�Ӵ��Ŀ�ͷ���ν��г���
        for(i=j;i<len;i++){
            if(arr[s[i]-' ']==0){//����ַ�û���ֹ�
                arr[s[i]-' ']=1;//�����ַ����б��
                num++;//���ȼ�1
            }
            else{
                memset(arr,0,sizeof(arr));//������Ϊ��
                break;
            }
        }
        max=max>num?max:num;//ȡ���ֵ
        num=0;//���¼���
    }
    return max;
}
