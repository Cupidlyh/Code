#include <stdio.h>
#include <stdlib.h>

int strStr(char * haystack, char * needle){//BF�㷨
    int h_len=strlen(haystack),n_len=strlen(needle),j=0,sign=-1,k;
    if(n_len==0)//�̴�����Ϊ0ʱ�϶����κ��ַ������Ӵ������Է���0
        return 0;
    //����forѭ�����ж��������������Ż��������к�����ַ��Ͳ���ÿһ�������¿�ʼ�Ƚϣ�ֱ�Ӳ��Ƚ�
    //��Ϊ����ĳ��ȶ�С�ڶ̴����϶�ƥ�䲻��
    for(k=0;k<=h_len-n_len;k++){
        if(haystack[k]==needle[j]){
                    //��¼����״����ʱk��ֵ�����ƥ��ʧ�ܣ�k��ֵҪ��ԭ
            sign=k;//ƥ������ɹ���ֱ�ӷ��������¼��kֵ
            j++;
            k++;
            while(haystack[k]==needle[j]&&j<n_len&&k<h_len){//ע�ⲻ�ܳ�����������ĳ���
                j++;
                k++;
            }
            if(j>=n_len)//���whileѭ������j�������ĳ��ȣ���˵��ƥ��ɹ���
                return sign;
            else{//��ƥ��ʧ��ʱ
                k=sign;//k�ָ�ԭ����ֵ����Ϊforѭ����k��Ҫ��һ�Σ��ʹﵽ�˴ӳ�����һ����ĸ��ʼ���±Ƚϵ�Ŀ��
                sign=-1;
                j=0;//j��Ϊ0���Ա��´��ж�
            }
        }
    }
    return sign;
}
